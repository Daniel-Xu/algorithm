import turtle

def tree(len, t):
    t.forward(len)
    t.right(20)
    tree(len-15, t)
    t.left(40)
    tree(len-15, t)
    t.right(20)
    t.backward(len)



def main():
    t = turtle.Turtle()
    myWin = turtle.Screen()
    t.left(90)
    t.up()
    t.backward(100)
    t.down()
    t.color('green')
    tree(75, t)
    myWin.exitonclick()

main()

