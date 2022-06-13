
""" 
import os
from PIL import Image



for file in os.listdir('garbage/0'):
    img = Image.open('garbage/0/'+file)
    print(img.size)
    img.thumbnail((400,300))
    print(img.size)
    img.save('garbage/0/'+file)


for file in os.listdir('garbage/1'):
    img = Image.open('garbage/1/'+file)
    print(img.size)
    img.thumbnail((400,300))
    print(img.size)
    img.save('garbage/1/'+file)

for file in os.listdir('garbage/2'):
    img = Image.open('garbage/2/'+file)
    print(img.size)
    img.thumbnail((400,300))
    print(img.size)
    img.save('garbage/2/'+file)

 """
import numpy as np
import random
a = np.array([1,2,3,4,5])
b = np.array([1,2,3,4,5])

c = list(zip(a,b))

random.shuffle(c)

a,b = zip(*c)

a = np.array(a)
b = np.array(b)


