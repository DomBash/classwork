
# coding: utf-8

# **Reinforment Learning AI Tic-Tac-Toe**
# 
# Created by: Dominic Bashford

# In[1]:


def saveData():
    if winner == o or winner == x or winner == c:
        incGames()
        with open("aiData.txt","r") as f:
            data = f.readlines()        
        for i in range(len(gameStates)):
            match = False
            for j in range(len(data)):  
                if str(gameStates[i]) == data[j][:-1]:
                    incWins(j)
                    match = True
            if match == False:
                addState(gameStates[i])
        f.close() 
    elif winner == n:
        incGames()
    else:
        return


# In[2]:


def incWins(index):
    with open("aiWins.txt") as f:
        data = f.readlines()
    data = [x.strip() for x in data] 
    if winner == o:
        wins = int(data[index]) + 2 #Weight of AI win
    elif winner == c:
        wins = int(data[index]) + 1 #Weight of draw
    else:
        wins = int(data[index]) - 2 #Weight of AI loss
    data[index] = str(wins)
    f = open("aiWins.txt","w")
    for i in range(len(data)):
        f.write(data[i] + "\n")
    f.close()


# In[3]:


def getWR(index):
    with open("aiWins.txt") as f:
        winData = f.readlines()
    winData = [x.strip() for x in winData]
    g = open("gameData.txt","r")
    games = g.read()
    return int(winData[index])/int(games)


# In[4]:


def addState(newState):
    with open("aiData.txt") as f:
        data = f.readlines()
    data = [x.strip() for x in data] 
    f = open("aiData.txt","a")
    f.write(str(newState) + "\n")
    f.close()
    
    f = open("aiWins.txt","a")
    if winner == o:
        f.write("2" + "\n")
    elif winner == x:
        f.write("-2" + "\n")
    else:
        f.write("1" + "\n")
    f.close()


# In[5]:


def incGames():
    f = open("gameData.txt","r")
    winNum = int(f.read()) + 1
    f.close
    f = open("gameData.txt","w")
    f.write(str(winNum))
    f.close()


# In[6]:


def AITurn():
    nm = nextMoveWR()
    state[nm[0]][nm[1]] = o
    print("AIs Move:")
    printBoard()


# In[7]:


def nextMoveWR():
    nexts = []
    stateIndex = []
    nextsWR = []
    with open("aiData.txt") as f:
        data = f.readlines()
    data = [x.strip() for x in data]
    for i in range(3):
        for j in range(3):
            if state[i][j] == n:
                nextState = copy.deepcopy(state)
                nextState[i][j] = o
                stateIndex.append((i,j))
                nexts.append(copy.deepcopy(nextState))
    
    for i in range(len(nexts)):
        newMatch = False
        for j in range(len(data)):
            if data[j] == str(nexts[i]):
                nextsWR.append(getWR(j))
                newMatch = True
            
        if newMatch == False:
            nextsWR.append(0)
    
    print(nextsWR)
    maxi = nextsWR[0]
    for i in range(len(nextsWR)):
        if nextsWR[i] > maxi:
            maxi = nextsWR[i]
    maxi = nextsWR.index(maxi)
        
    if nextsWR.count(nextsWR[maxi]) > 1:
        same = nextsWR[maxi]
        sames = []
        for i in range(len(nextsWR)):
            if nextsWR[i] == same:
                sames.append(i)
        return stateIndex[random.choice(sames)]         
            
    else:
        return stateIndex[maxi]


# In[8]:


def playerTurn():
    new = False
    while new == False:
        
        print("Your move: ")
        move = input()
        
        if len(move) < 2:
            print("2 numbers required.")
            printBoard()
        elif move == "xx" or checkWin() == True:
            return True
        else:
            if state[int(move[0])][int(move[1])] == n:
                state[int(move[0])][int(move[1])] = x
                return False
            else:
                print("Space already taken. Pick a different one.")
                printBoard()


# In[9]:


def printBoard():
    
    print("")
    print("   0 | 1 | 2 ")
    print("  -----------")
    print("0|",state[0][0],"|",state[0][1],"|",state[0][2],"")
    print("  -----------")
    print("1|",state[1][0],"|",state[1][1],"|",state[1][2],"")
    print("  -----------")
    print("2|",state[2][0],"|",state[2][1],"|",state[2][2],"")
    print("")


# In[10]:


def checkWin():
    
    #Horizon
    if state[0][0] == state[0][1] == state[0][2] != n:
        print("The winner is: ", state[0][0])
        return True
    elif state[1][0] == state[1][1] == state[1][2] != n:
        print("The winner is: ", state[1][0])
        return True
    elif state[2][0] == state[2][1] == state[2][2] != n:
        print("The winner is: ", state[2][0])
        return True
        
    #Vertical
    elif state[0][0] == state[1][0] == state[2][0] != n:
        print("The winner is: ", state[0][0])
        return True
    elif state[0][1] == state[1][1] == state[2][1] != n:
        print("The winner is: ", state[0][1])
        return True
    elif state[0][2] == state[1][2] == state[2][2] != n:
        print("The winner is: ", state[0][2])
        return True
        
    #Diagonal
    elif state[0][0] == state[1][1] == state[2][2] != n:
        print("The winner is: ", state[0][0])
        return True
    elif state[2][0] == state[1][1] == state[0][2] != n:
        print("The winner is: ", state[2][0])
        return True
    else:
        return False
    


# In[11]:


def getRand():
    r1 = random.randint(0,2)
    r2 = random.randint(0,2)
    if state[r1][r2] == n:
        return(r1,r2)
    else:
        return getRand()


# In[25]:


print("")
print("Move Reference Sheet:")
print("")
print("   0 | 1 | 2 ")
print("  -----------")
print("0| 00| 01| 02")
print("  -----------")
print("1| 10| 11| 12")
print("  -----------")
print("2| 20| 11| 22")
print("")
print("Input 'xx' to end game")


# In[27]:


import random
import copy

x = "X"
o = "O"
n = " "
c = "C"
winner = n
count = 0
win = False
exit = False
gameStates = []
state = [[n, n, n],
         [n, n, n],
         [n, n, n]]

while exit == False and count < 5:
    
    if checkWin() == False:
            AITurn()
            gameStates.append(copy.deepcopy(state))
            winner = o
            count += 1

            if checkWin() == False: 
                if count == 5:
                    print("Cat's Game")
                    winner = c
                    exit = True
                    saveData()
                    
                else:
                    exit = playerTurn()
                    winner = x
                
            else: 
                exit = True
                saveData()
    else: 
        exit = True
        saveData()
    
   
    printBoard()

