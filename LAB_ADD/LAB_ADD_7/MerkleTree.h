#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

class MerkleTree {
public:
  struct ProofStep {
    std::string siblingHash;
    bool isLeftSibling;
  };

  MerkleTree() = default;
  explicit MerkleTree(const std::vector<std::string> &leafData);

  bool empty() const { return leaves.empty(); }
  std::size_t leafCount() const { return leaves.size(); }

  void setLeaves(const std::vector<std::string> &leafData);
  void addLeaf(const std::string &data);

  const std::vector<std::string> &getLeaves() const { return leaves; }
  std::string rootHash() const;

  std::vector<ProofStep> buildProof(std::size_t leafIndex) const;
  static bool verifyProof(const std::string &leafData,
                          const std::vector<ProofStep> &proof,
                          const std::string &expectedRoot);

private:
  std::vector<std::string> leaves;
  std::vector<std::vector<std::string>> levels;

  static std::string hashData(const std::string &data);
  static std::string hashPair(const std::string &left,
                              const std::string &right);

  void rebuild();
};
