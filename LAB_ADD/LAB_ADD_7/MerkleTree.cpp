#include "MerkleTree.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <utility>

namespace {
constexpr std::uint64_t kFnvOffset = 14695981039346656037ull;
constexpr std::uint64_t kFnvPrime = 1099511628211ull;

std::string hashString(const std::string &data) {
  std::uint64_t hash = kFnvOffset;
  for (unsigned char byte : data) {
    hash ^= static_cast<std::uint64_t>(byte);
    hash *= kFnvPrime;
  }

  std::ostringstream os;
  os << std::hex << std::setfill('0') << std::setw(16) << hash;
  return os.str();
}
}

MerkleTree::MerkleTree(const std::vector<std::string> &leafData) {
  setLeaves(leafData);
}

void MerkleTree::setLeaves(const std::vector<std::string> &leafData) {
  leaves = leafData;
  rebuild();
}

void MerkleTree::addLeaf(const std::string &data) {
  leaves.push_back(data);
  rebuild();
}

std::string MerkleTree::rootHash() const {
  if (levels.empty()) {
    return {};
  }
  return levels.back().front();
}

std::vector<MerkleTree::ProofStep>
MerkleTree::buildProof(std::size_t leafIndex) const {
  if (levels.empty()) {
    throw std::logic_error("Cannot build proof for an empty tree");
  }
  if (leafIndex >= leaves.size()) {
    throw std::out_of_range("Leaf index is outside of the tree");
  }

  std::vector<ProofStep> proof;
  std::size_t index = leafIndex;
  for (std::size_t level = 0; level + 1 < levels.size(); ++level) {
    const auto &currentLevel = levels[level];

    const bool isRightChild = index % 2 == 1;
    const std::size_t siblingIndex = isRightChild ? index - 1 : index + 1;
    const bool hasSibling = siblingIndex < currentLevel.size();
    const std::string &sibling =
        hasSibling ? currentLevel[siblingIndex] : currentLevel[index];

    proof.push_back({sibling, isRightChild});
    index /= 2;
  }

  return proof;
}

bool MerkleTree::verifyProof(const std::string &leafData,
                             const std::vector<ProofStep> &proof,
                             const std::string &expectedRoot) {
  if (expectedRoot.empty()) {
    return false;
  }

  std::string hash = hashData(leafData);
  for (const auto &step : proof) {
    if (step.isLeftSibling) {
      hash = hashPair(step.siblingHash, hash);
    } else {
      hash = hashPair(hash, step.siblingHash);
    }
  }

  return hash == expectedRoot;
}

std::string MerkleTree::hashData(const std::string &data) {
  return hashString(data);
}

std::string MerkleTree::hashPair(const std::string &left,
                                 const std::string &right) {
  return hashData(left + right);
}

void MerkleTree::rebuild() {
  levels.clear();
  if (leaves.empty()) {
    return;
  }

  levels.emplace_back();
  for (const auto &leaf : leaves) {
    levels.back().push_back(hashData(leaf));
  }

  while (levels.back().size() > 1) {
    const auto &previous = levels.back();
    std::vector<std::string> nextLevel;
    nextLevel.reserve((previous.size() + 1) / 2);

    for (std::size_t i = 0; i < previous.size(); i += 2) {
      const std::string &left = previous[i];
      const std::string &right = (i + 1 < previous.size()) ? previous[i + 1] : previous[i];
      nextLevel.push_back(hashPair(left, right));
    }

    levels.emplace_back(std::move(nextLevel));
  }
}
