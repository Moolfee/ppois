#include "MerkleTree.h"

#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> data{"alpha", "beta", "gamma", "delta"};
  MerkleTree tree(data);

  std::cout << "Leaves:\n";
  for (std::size_t i = 0; i < tree.leafCount(); ++i) {
    std::cout << "  [" << i << "] " << tree.getLeaves()[i] << '\n';
  }

  std::cout << "Root hash: " << tree.rootHash() << "\n\n";

  const std::size_t targetIndex = 2;
  auto proof = tree.buildProof(targetIndex);

  std::cout << "Proof for index " << targetIndex << ":\n";
  for (const auto &step : proof) {
    std::cout << (step.isLeftSibling ? "L" : "R")
              << " sibling: " << step.siblingHash << '\n';
  }

  const bool ok =
      MerkleTree::verifyProof(data[targetIndex], proof, tree.rootHash());
  std::cout << "Verification: " << (ok ? "success" : "failed") << '\n';
}
