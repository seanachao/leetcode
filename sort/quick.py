import random
a = [random.randint(0,500)%50 for x in range(0,50)]
print(a)
def swap(a,b):
    temp = a
    a = b
    b = temp
def quick_sort(data,l,r):
    temp = l
    left = l+1
    right = r
    #按照从小到大排序，
    while left <= right:
        while left<= right and data[temp] <= data[right]:
            print("DDD")
            right -= 1
        while left<= right and data[temp] >= data[left]:
            left += 1
        if(left <= right and data[left]!=data[right]):
            swap(data[right],data[left])
        #print("EEEEEEEEEE")
    quick_sort(data,l,left)
    quick_sort(data,left+1,r)
quick_sort(a,0,len(a)-1)