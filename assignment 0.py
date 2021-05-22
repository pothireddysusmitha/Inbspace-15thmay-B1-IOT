#1.To print all even numbers from a given numbers list in the same order and stoo printing that come
#after 237
a=[386,462,47,418,907,344,236,375,823,566,597,978,328,615,953,345,399,162,758,219,918,237,412,566,248,
   866,950,626,949,687,217,815,67,104,58,512,24,892,894,767,553,81,379,843,831,445,742,717,958,743,527]
for i in a:
    if i==237:
        print(i)
        break
    elif i%2==0:
        print(i)
#2.To print out a set containing all the colors in list 1 which are not present in list 2
color_list_1=set(["White","Black","Red"])
color_list_2=set(["Red","Green"])
print(color_list_1.difference(color_list_2))                  

#3.To accept an tnteger and computes the value of n+nn+nnn
n=input("Enter an integer:")
n1=int(f"{n}")
n2=int(f"{n}{n}")
n3=int(f"{n}{n}{n}")
n4=n1+n2+n3
print(n1)
print(n2)
print(f"computed value of {n1}+{n2}+{n3}= {n4} ")
#4.To find if the given input is pangram or not
import string
def ispangram(str):
    alphabet="abcdefghijklmnoparstuvwxyz"
    for char in alphabet:
        return False
    return True
string='the five boxing wizards jump quickly .'
if(ispangram(string)==True):
    print("it is a pangraam:")
else:
    print("it is not a pangram:")
#5.Program To take input from console in following fashion 
input_string=input('enter the string in required fashion :')
input_list=input_string.split('#')
list_1=input_list[0].split()
list_2=input_list[1].split()
list_1=[int(i) for i in list_1]
list_2=[int(i) for i in list_2]
print('list 1:',list_1)
print('list 2:',list_2)
 
#6.program thataccepts a comma seperated sequence of words as input and prints the words in a comma
#seperated sequenceafter sorting
items=input("input comma seperated sequence of words ")
words=[word for word in items .split(",")]
print(",".join(sorted(list(set(words)))))
#7.accepts a sentence and calculate the number of letters and digits
s=input("input a string")
d=l=0
for c in s:
    if c.isdigit():
        d=d+1
    elif c.isalpha():
         l=l+1
    else:
        pass
print("Letters ",l)
print("Digits",d)
#8.to find the nmae of a personobtained hihest marks i exam from given dictionary
d = {'rahul':57,'kishore':87,'vidhya':67,'raakhi':79}
print(max(d,key=d.get))
#Question 9
d={'name':['akash','soniya','vishakha','akshay','rahul','vikas'],'subjects':
   ['python','java','python','java','c','python','java'],'ratings':['8.4','7.8','8.9','8.2','5.6']}
newdata={'name':[],'ratings':[]}
index=0
for sub in d['subjects']:
    if(sub=='python'):
        newdata['name'].append(d['name'][index])
        newdata['ratings'].append(d['ratings'][index])
        index+=1
print('new dictionary of students:',newdata)
    

#10. a class with a generator which can iterate numbers,which are divisible by7
class iterator(object):
	
	def __init__(self, n):
		super(iterator, self).__init__()
		self.n = n
		
	def divBySeven(self):
		for i in range(0, self.n):
			if i % 7 == 0:
				yield i

for num in iterator(100).divBySeven():
	print(num)    


#question 11
pos = {"x": 0, "y": 0}

while True:

    n = input()
    if not n:
        break

    direction,steps=n.split()
    if direction == "UP":
        pos["y"] += int(steps)
    elif direction == "DOWN":
        pos["y"] -= int(steps)
    elif direction == "LEFT":
        pos["x"] -= int(steps)
    elif direction == "RIGHT":
        pos["x"] += int(steps)
print (int(round((pos["x"]**2 + pos["y"]**2)**0.5)))

