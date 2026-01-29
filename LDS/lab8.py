binary_tree = {
    "value" : 2,
    "left":
    {
        "value": 20, "left": {
            "value": 10,
            "left":
            {
                "value": 5,
                "left": None,
                "right": None
            },
            "right":
            {
            "value":11, "left": None, "right": None
            },
        }, "right":
        {
            "value": 30,
            "left":
            {
                "value": 22,
                "left": None,
                "right": None
            },
            "right":
            {
            "value":31, "left": None, "right": None
            },
        },
    },
    "right":
    {
        "value": 1,
        "left":  None,
        "right": None
    }
}

arbitrary_tree = [
    {"value" : 1, "children" : [2,3,4]},
    {"value" : 2, "children" : []},
    {"value" : 3, "children" : [5,6]},
    {"value" : 4, "children" : []},
    {"value" : 5, "children" : []},
    {"value" : 6, "children" : []},
]


# print(binary_tree["left"])
def inorder(tree):
    if(tree != None):
        return  inorder(tree["left"]) +[tree["value"]] +inorder(tree["right"])
    else:
        return []
print(inorder(binary_tree))

print("---------- Exercise 1 ----------")

#nodes that have a single child
def inorder_only_nodes_with_1_child(tree):
    if(tree != None):
       child = 0
       result1 = inorder_only_nodes_with_1_child(tree["left"])
       result2 = inorder_only_nodes_with_1_child(tree["right"])
       if(tree["left"] != None):
           child += 1
       if(tree["right"] != None):
           child += 1
       if(child == 1):
           return result1 + [tree["value"]] + result2
       else:
           return result1 + result2
    else:
        return []
print(inorder_only_nodes_with_1_child(binary_tree))


print("---------- Exercise 2 ----------")

def count_nodes(tree):
    if(tree != None):
        return count_nodes(tree["left"]) + 1 + count_nodes(tree["right"])
    else:
        return 0
print(count_nodes(binary_tree))

print("---------- Exercise 3 ----------")

def inorder_arbitrary_tree(tree, root):
    print("root is:", root)
    root = root - 1
    if(tree[root]["children"] != []):
        #return  inorder(tree["left"]) +[tree["value"]] +inorder(tree["right"])
        #print(tree[0])
        #print(tree[start_node])
        print("children:", tree[root]["children"])
        list_children = tree[root]["children"]
        #print("now we go to", list_children[0])
        inorder_arbitrary_tree(tree, list_children[0])
        for child in list_children[1:]:
            inorder_arbitrary_tree(tree, child)
        #print("finished node: ", start_node + 1)
    else:
        return []
print(inorder_arbitrary_tree(arbitrary_tree,1))


print("---------- Exercise 4 ----------")

def indented_printing(tree,spaces):
    if(tree != None):
        print(" " * 2 * spaces, [tree["value"]])
        return  [tree["value"]] + indented_printing(tree["left"], spaces + 1) +indented_printing(tree["right"], spaces+1)
    else:
        return []
indented_printing(binary_tree,0)

# [2]
#    [7]
#      [6]
#        [5]
#        [11]
#    [4]
#      [12]


print("---------- Exercise 5 ----------")


print("---------- Insert Node ---------")

def insert_node(node,x):
    if(node == None):
        return {"value" : x, "left" : None, "right" : None}
    if x < node["value"]:
        node["left"] = insert_node(node["left"],x)
    elif x > node["value"]:
        node["right"] = insert_node(node["right"],x)
    return node
insert_node(binary_tree,17)
print(indented_printing(binary_tree,0))


