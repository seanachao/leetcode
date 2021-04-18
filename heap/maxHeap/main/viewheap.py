# move.py
# 1. 导入gdb模块来访问gdb提供的python接口
import gdb
 
class Tree():
    def __init__(self,treelist=None):
        self.a = treelist if treelist else [2*x for x in range(32)]
        self.length = len(self.a)

    def get_tree_depth(self,ptr):
        if (ptr > self.length):
            return 0;
        else:
            return 1 + max(self.get_tree_depth(ptr*2),self.get_tree_depth(ptr*2+1))
    def print_tree(self):
        tree_height = self.get_tree_depth(1)
        
        b = [0,1]
        k = 1
        weight = 3
        data = " "*(2**(tree_height)-1)*weight
        print(data,self.a[1])
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
# 2. 用户自定义命令需要继承自gdb.Command类
class Move(gdb.Command):
 
    # 3. docstring里面的文本是不是很眼熟？gdb会提取该类的__doc__属性作为对应命令的文档
    """Move breakpoint
    Usage: mv old_breakpoint_num new_breakpoint
    Example:
        (gdb) mv 1 binary_search -- move breakpoint 1 to `b binary_search`
    """
 
    def __init__(self):
        # 4. 在构造函数中注册该命令的名字
        super(self.__class__, self).__init__("pcr", gdb.COMMAND_USER)
 
    # 5. 在invoke方法中实现该自定义命令具体的功能
    # args表示该命令后面所衔接的参数，这里通过string_to_argv转换成数组
    def invoke(self, args, from_tty):
        argv = gdb.string_to_argv(args)
        print(argv)
        #if len(argv) != 2:
        #    raise gdb.GdbError('输入参数数目不对，help mv以获得用法')
        # 6. 使用gdb.execute来执行具体的命令
        #gdb.execute('p/x *core->rcmd')
        # f = open('1.txt','w')
        # for i in range(0,1000):
        #     cmdline = 'p *(RzCmdDesc*)ht->table[{}]->arr->value'.format(i)
        #     cmdline = 'p a'
        #     try:
        #         f.write(str(i)+'\n')
        #         data = gdb.execute(cmdline,to_string=True)
        #         f.write(str(data))
        #     except:
        #         pass
        # f.close()
        #print("hello world")
        data = gdb.parse_and_eval(argv[0])
        data = data.format_string().strip('{').strip('}').split(',')
        # cmd_line = "p *heap@10"

        # data = gdb.execute(cmd_line,to_string=True)
        # data = data.strip('{').strip('}').split(',')
        
        print(data)
        data = [int(x) for x in data]
        get_tree = Tree(data)
        get_tree.print_tree()

# 7. 向gdb会话注册该自定义命令

Move()