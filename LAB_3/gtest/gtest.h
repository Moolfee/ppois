#pragma once

#include <exception>
#include <functional>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace testing {
struct TestCase {
    std::string suite;
    std::string name;
    std::function<void()> body;
};

inline std::vector<TestCase>& Registry() {
    static std::vector<TestCase> registry;
    return registry;
}

inline int& FailureCount() {
    static int failures = 0;
    return failures;
}

inline void ResetFailures() {
    FailureCount() = 0;
}

inline void ReportFailure(const char* file,
                          int line,
                          const std::string& expression,
                          const std::string& message) {
    std::cerr << file << ":" << line << ": Failure\n"
              << "  Expression: " << expression << "\n";
    if (!message.empty()) {
        std::cerr << "  Message   : " << message << "\n";
    }
    FailureCount() += 1;
}

struct TestRegistrar {
    TestRegistrar(std::string suite, std::string name, std::function<void()> body) {
        Registry().push_back(TestCase{std::move(suite), std::move(name), std::move(body)});
    }
};

inline void InitGoogleTest(int*, char**) {}

inline int RunAllTests() {
    int failedSuites = 0;
    for (const auto& test : Registry()) {
        std::cout << "[ RUN      ] " << test.suite << "." << test.name << "\n";
        ResetFailures();
        try {
            test.body();
        } catch (const std::exception& ex) {
            ReportFailure(__FILE__, __LINE__, "Unhandled exception", ex.what());
        } catch (...) {
            ReportFailure(__FILE__, __LINE__, "Unhandled exception", "unknown error");
        }
        if (FailureCount() == 0) {
            std::cout << "[       OK ] " << test.suite << "." << test.name << "\n";
        } else {
            std::cout << "[  FAILED  ] " << test.suite << "." << test.name << " (" << FailureCount()
                      << " failures)\n";
            failedSuites += 1;
        }
    }
    const int passed = static_cast<int>(Registry().size()) - failedSuites;
    std::cout << "\nSummary: " << passed << " passed, " << failedSuites << " failed.\n";
    return failedSuites == 0 ? 0 : 1;
}

inline void ExpectTrue(bool condition,
                       const char* expression,
                       const char* file,
                       int line,
                       const std::string& message = {}) {
    if (!condition) {
        ReportFailure(file, line, expression, message);
    }
}

template <typename LHS, typename RHS>
inline void ExpectBinary(bool condition,
                         const LHS& lhs,
                         const RHS& rhs,
                         const char* lhsText,
                         const char* rhsText,
                         const char* op,
                         const char* file,
                         int line) {
    if (!condition) {
        std::ostringstream oss;
        oss << lhsText << " " << op << " " << rhsText << " (" << lhs << " vs " << rhs << ")";
        ReportFailure(file, line, oss.str(), "");
    }
}
}  

#define TEST(test_case_name, test_name)                                                         \
    void test_case_name##_##test_name();                                                        \
    static ::testing::TestRegistrar test_case_name##_##test_name##_registrar(                   \
        #test_case_name, #test_name, []() { test_case_name##_##test_name(); });                 \
    void test_case_name##_##test_name()

#define EXPECT_TRUE(condition)                                                                 \
    ::testing::ExpectTrue(static_cast<bool>(condition), #condition, __FILE__, __LINE__)

#define EXPECT_EQ(val1, val2)                                                                  \
    ::testing::ExpectBinary(((val1) == (val2)), val1, val2, #val1, #val2, "==", __FILE__, __LINE__)

#define EXPECT_NE(val1, val2)                                                                  \
    ::testing::ExpectBinary(((val1) != (val2)), val1, val2, #val1, #val2, "!=", __FILE__, __LINE__)

#define EXPECT_GT(val1, val2)                                                                  \
    ::testing::ExpectBinary(((val1) > (val2)), val1, val2, #val1, #val2, ">", __FILE__, __LINE__)

#define RUN_ALL_TESTS() ::testing::RunAllTests()