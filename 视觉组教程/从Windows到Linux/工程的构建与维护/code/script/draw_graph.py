from itertools import combinations
from graphviz import Graph

if __name__ == "__main__":
    g = Graph(format="png")
    states = ["state1", "state2", "state3", "state4"]
    coms = combinations(states, 2)
    for com in coms:
        g.edge(com[0], com[1])
    g.view()
