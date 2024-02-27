import re
from graphviz import Digraph


class ListNode:
    def __init__(self, address, data, next_node):
        self.address = address
        self.data = data
        self.next_node = next_node

    def getInfo(self):
        return f"{self.address}"


def MatchNode(s):
    list_node_strs = s.split(".)")
    list_nodes = []
    for list_node_str in list_node_strs:
        if list_node_str == "":
            continue
        split_strs = list_node_str.split(";")
        address = split_strs[0][20:]
        next_node = split_strs[1][14:]
        data = split_strs[2][6:]
        node = ListNode(address, data, next_node)
        list_nodes.append(node)
    return list_nodes


if __name__ == "__main__":
    dot = Digraph(format="png", comment="List")
    input = input()
    list_nodes = MatchNode(input)
    for node in list_nodes:
        if node.next_node == "(nil)":
            continue
        dot.edge(node.address, node.next_node, constraint="false")

    # for i in range(len(nodes) - 1):
    #     dot.edge(nodes[i], nodes[i + 1], constraint="false")

    # dot.edge("node1", "node2", constraint="false")
    dot.view("png")
