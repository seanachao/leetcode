a = [0]
def find_op(data,l,r):
    h = 0
    for _ in range(len(data)-1,-1,-1):
        #print(_)      
        if data[_] > h:
            h+=1
    print(h)
    return h
    #pass

if __name__ == '__main__':
    find_op(a,0,len(a)-1)