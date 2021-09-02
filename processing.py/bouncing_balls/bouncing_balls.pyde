width = 600
height = 600
r = 20
n = 20

import random as rd
class Ball:
    
    def __init__(self):
        self.x = width/2
        self.y = width/2
        self.xspeed = rd.randint(1,20)
        self.yspeed = rd.randint(1,20)
        
        
    def move(self):
        self.x += self.xspeed
        self.y += self.yspeed
        
    
    def bounce(self):
        if (self.x < r) or (self.x > width-r):
            self.xspeed = -self.xspeed
        if (self.y < r) or (self.y > height-r):
            self.yspeed = -self.yspeed
    
        
    def display(self):
        fill(255)
        strokeWeight(2)
        stroke(0)
        ellipse(self.x,self.y,r,r)
Balls = [Ball() for i in range(n)]


#ball1 = Ball(width/2,height/2)

def setup():
    size(600,600, P2D)
    noStroke()

def draw():
    background(52)
    for i in range(n):
        Balls[i].move()
        Balls[i].bounce()
        Balls[i].display()
    
        
        
#print (ball1.xspeed,ball1.yspeed)
print (Balls)
