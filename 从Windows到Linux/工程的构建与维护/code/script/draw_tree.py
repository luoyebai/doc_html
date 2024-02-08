import re
from graphviz import Digraph


def MatchState(s):
    it = re.finditer("{(.+?)\}", s)
    return it


def GetStateName(s):
    it = re.finditer(r"(.*?)\[(.*?)\](.*?)", s)
    try:
        return f"{next(it).group()}"[1:]
    except Exception:
        return "None"


def GetStateData(s):
    it = re.finditer(r"(.*?)\((.*?)\)(.*?)", s)
    try:
        return next(it)
    except Exception:
        return []


if __name__ == "__main__":
    pass
    dot = Digraph(format="png", comment="这是一个测试")

    nodes = []

    input = input()
    states = MatchState(input)
    for state in states:
        state_name = GetStateName(f"{state.group()}")
        # print(state_name)
        for list_node in state_data:
            print(list_node.group())

    for i in range(len(nodes) - 1):
        dot.edge(nodes[i], nodes[i + 1], constraint="false")

    # dot.edge("node1", "node2", constraint="false")
    dot.view("png")
