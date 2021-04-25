import sys
sys.setrecursionlimit(10**6)


class Tree:
    def __init__(self, nodes):
        self.data = max(nodes, key=lambda x: x[1])
        left_nodes = list(filter(lambda x: x[0] < self.data[0], nodes))
        right_nodes = list(filter(lambda x: x[0] > self.data[0], nodes))

        if left_nodes:
            self.left = Tree(left_nodes)
        else:
            self.left = None

        if right_nodes:
            self.right = Tree(right_nodes)
        else:
            self.right = None


def solution(nodeinfo):
    root = Tree(nodeinfo)
    pre, post = [], []

    def traverse(node):
        pre.append(nodeinfo.index(node.data) + 1)
        if node.left is not None:
            traverse(node.left)
        if node.right is not None:
            traverse(node.right)
        post.append(nodeinfo.index(node.data) + 1)

    traverse(root)
    return pre, post
