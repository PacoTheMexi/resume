class Ball:
    def __init__(self,x,y):
        self.x = x
        self.y = y
        self.xspeed = 0
        self.yspeed = 0
        
    def move(self, xspeed, yspeed):
        self.x += xspeed
        self.y += yspeed
        
    def display(self):
        ellipse(self.x,self.y,20,20)
    
