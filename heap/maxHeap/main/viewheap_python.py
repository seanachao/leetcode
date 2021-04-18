class Tree():
    def __init__(self,treelist=None):
        self.a = treelist if treelist else [x for x in range(32)]
        self.length = len(self.a)

    def get_tree_depth(self,ptr):
        if (ptr > self.length):
            return 0;
        else:
            return 1 + max(self.get_tree_depth(ptr*2),self.get_tree_depth(ptr*2+1))
    def print_tree(self):
        tree_height = self.get_tree_depth(1)
        tree_height -=1
        b = [0,1]
        k = 1
        weight = 3
        data = " "*(2**(tree_height)-1)*weight
        print(data,"1")
        for i in range(1,tree_height):
            c = b[k:] #记录上一层
            data = " "*(2**(tree_height-i)-1)*weight
            print(data,end="")
            for node in c:        
                if( 2 * node+1 < self.length):
                    k+=1
                    data_mid = " "*(2**(tree_height-i+1)-1)*weight
                    fmt_data = "{:>3d}{}{:>3d}".format(self.a[node*2],data_mid,self.a[node*2+1],data_mid)
                    print(fmt_data,end=data_mid)
                    b.append(node*2)
                    b.append(node*2+1)
            print(" ")

b = [ x for x in range(20)]
Tree_example = Tree(b)
Tree_example.print_tree()