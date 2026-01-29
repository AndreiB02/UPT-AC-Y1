graph = {
    1 : [5,3,4],
    2 : [1,3],
    3 : [1,4],
    4 : [1,3],
    5: []
}
graf = {
    "a" : ["b", "c"],
    "b" : ["a"],
    "c" : ["a"],
}

print(" ------ ex1 - test ------")
def degree_node(graph, nodes):
    if nodes == []:
        return
    print(nodes[0] , " " ,len(graph[nodes[0]]) )
    degree_node(graph, nodes[1:])

degree_node(graph, list(graph.keys()))
print(" ----- ex2 - DFS -------")
def DFS(graph, start_node, visited = []):
    if start_node not in visited:
        print(start_node)
        visited.append(start_node)
        for n in graph[start_node]:
            DFS(graph, n)

DFS(graph, 1)

print(" ----- ex1 -----")

def all_nodes(nodes):
    if nodes == []:
        return
    else:
        print(nodes[0])
        all_nodes(nodes[1:])
all_nodes(list(graf.keys()))


print(" ----- ex2 -----")
def neighbours_of_a_node(graph, searched_node):
    print(graph[searched_node])

neighbours_of_a_node(graf, "a")

print("----- ex3 -----")
def count_nodes(graph):
    print(len(graph.keys()))
count_nodes(graf)

print("----- ex4 -----")
def count_neighbours_for_each_node(graph, keys):
    if keys != []:
        print(keys[0])
        print(len(graph[keys[0]]))
        count_neighbours_for_each_node(graph, keys[1:])
count_neighbours_for_each_node(graf, list(graf.keys()))


graf = {
    "a" : ["b"],
    "b" : ["a", "c"],
    "c" : ["b"],
}
import functools
print("----- ex5 -----")
def dictionary_to_edge_list(graph, keys, edges = []):
    if keys != []:
        #print(keys[0])
        #print(edges)
        def f(acc, elem):
            #print((keys[0], elem))
            edges.append((keys[0], elem))
        functools.reduce(f, graph[keys[0]], "some value just to be")
        dictionary_to_edge_list(graph, keys[1:], edges)
    return edges


print(dictionary_to_edge_list(graf, list(graf.keys())))

