class Node:
    def __init__(self, char, data=None):
        self.char = char
        self.data = data
        self.children = {}
        self.data_num = 0


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        cur_node = self.head
        for char in string:
            if char not in cur_node.children:
                cur_node.children[char] = Node(char)
            cur_node = cur_node.children[char]
            cur_node.data_num += 1
        cur_node.data = string

    def search(self, string):
        cur_node = self.head
        count = 0
        for char in string:
            if char not in cur_node.children:
                return 0
            cur_node = cur_node.children[char]
            count += 1
            if cur_node.data_num == 1:
                return count
        return count


def solution(words):
    answer = 0
    trie = Trie()

    for word in words:
        trie.insert(word)
    for word in words:
        answer += trie.search(word)

    return answer
