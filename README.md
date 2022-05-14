# Scapegoat-Tree
This project is from my CSE-225 course in 5th semester at NSU. This is a complete project for Scapegoat Tree.

A scapegoat tree is a self-balancing binary tree. Arne Andersson invented it in 1989. Scapegoat is based on the common saying, “when something goes wrong, find a scapegoat.” We can say that the scenario for scapegoat trees is the same. Scapegoat trees choose a scapegoat and completely rebuild the subtree rooted at the scapegoat into a complete binary tree.
Unlike most other self-balancing binary search trees which provide worst case O(log n) lookup time, scapegoat trees have no additional per-node memory overhead compared to a regular binary search tree: besides key and value, a node stores only two pointers to the child nodes. This makes scapegoat trees easier to implement and, due to data structure alignment, can reduce node overhead by up to one-third.
Instead of the small incremental rebalancing operations used by most balanced tree algorithms, scapegoat trees rarely but expensively choose a "scapegoat" and completely rebuild the subtree rooted at the scapegoat into a complete binary tree. Thus, scapegoat trees have O(n) worst-case update performance.

[Initial Menu of the Project]
![initial look](https://user-images.githubusercontent.com/62169118/168446997-17698c08-6ed8-47b5-8386-d0752d506221.PNG)

[Initial Normal AVL Tree]
![the tree](https://user-images.githubusercontent.com/62169118/168446971-92cba29b-cd01-4a6c-8db4-79fbcfae8268.PNG)

[Finding ScapeGoat]
![finding scapegoat](https://user-images.githubusercontent.com/62169118/168447041-d3abb621-e62f-4c41-8745-7d59d3fc427e.PNG)

[Automatically Rebuilt AVL Tree after finding scapegoat]
![tree after finding scapegoat](https://user-images.githubusercontent.com/62169118/168447045-69b5c412-1904-4f03-9ec9-8d408608eee1.PNG)

