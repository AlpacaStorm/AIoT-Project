import requests
import numpy as np
import socket
from tensorflow import keras
bind_ip = "我的ip不給你看"
bind_port = 8888

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind((bind_ip,bind_port))
server.listen(2)
model = keras.models.load_model('cnn')

while True:
    client,addr = server.accept()

    while not client.recv(100) :
        pass
    
    r=requests.get('http://192.168.1.113/capture.jpg')

    predict_x=model.predict([r.content])
    classes_x=np.argmax(predict_x,axis=1)

    if(classes_x==2):
        client.send('0')
    else:
        client.send('1')


