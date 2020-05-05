# Name: Dominic B
# Date: 9/28/15
# Program: Connect4 Game
# Description: A simple game of connect four using pyGame

import pygame
pygame.init()

print("Welcome to Connect4!")
print("Blue starts!")

size = [350,300]
screen = pygame.display.set_mode(size)

pygame.display.set_caption("Connect 4")

def initScreen(): #Initialize the screen
	width = 0
	height = 0
	while width < 350:
		width += 50
		pygame.draw.line(screen, (225,225,0), (width,0), (width,300))
	while height < 300:
		height += 50
		pygame.draw.line(screen, (225,225,0), (0,height), (350,height))

	myfont = pygame.font.SysFont("helvetica", 46)
	numWidth = 10
	num = 0
	while num <= 7:
		num += 1
		strnum = str(num)	
		number = myfont.render(strnum, 1, (25,25,25))
		screen.blit(number, (numWidth, 1))
		numWidth += 50	
	
	pygame.display.flip()

def checkTurn(turn): #Check whos turn it is
	if turn == 0:
		turn = 1
	else:
		turn = 0
	return(turn)

def drawRect(x,y,turn): #Draw the pieces
	turn = checkTurn(turn)
	if turn == 0:
		pygame.draw.rect(screen, (255,0,0), (x+1,y+1,49,49))
	else:
		pygame.draw.rect(screen, (0,0,255), (x+1,y+1,49,49))

	pygame.display.flip()

	return(turn)

def checkLine(lineChecking,x,turn): #Check the column on the board
	full = 1
	if lineChecking[0] != full:
		y = 250
		turn = drawRect(x,y,turn)
		lineChecking[0] = full
	elif lineChecking[1] != full:
		y = 200
		turn = drawRect(x,y,turn)
		lineChecking[1] = full
	elif lineChecking[2] != full:
		y = 150
		turn = drawRect(x,y,turn)
		lineChecking[2] = full
	elif lineChecking[3] != full:
		y = 100
		turn = drawRect(x,y,turn)
		lineChecking[3] = full
	elif lineChecking[4] != full:
		y = 50
		turn = drawRect(x,y,turn)
		lineChecking[4] = full
	elif lineChecking[5] != full:
		y = 0
		turn = drawRect(x,y,turn)
		lineChecking[5] = full
	return(turn)

def main():
	initScreen()	
	
	line1 = [0,0,0,0,0,0]
	line2 = [0,0,0,0,0,0]
	line3 = [0,0,0,0,0,0]
	line4 = [0,0,0,0,0,0]
	line5 = [0,0,0,0,0,0]
	line6 = [0,0,0,0,0,0]
	line7 = [0,0,0,0,0,0]

	running = True
	turn = 0
	
	while running:			
		for event in pygame.event.get():
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_1:
						x = 0
						lineChecking = line1
						turn = checkLine(lineChecking,x,turn)
				elif event.key == pygame.K_2:
						x = 50
						lineChecking = line2
						turn = checkLine(lineChecking,x,turn)
				elif event.key == pygame.K_3:
						x = 100
						lineChecking = line3
						turn = checkLine(lineChecking,x,turn)
				elif event.key == pygame.K_4:
						x = 150
						lineChecking = line4
						turn = checkLine(lineChecking,x,turn)
				elif event.key == pygame.K_5:
						x = 200
						lineChecking = line5
						turn = checkLine(lineChecking,x,turn)
				elif event.key == pygame.K_6:
						x = 250
						lineChecking = line6
						turn = checkLine(lineChecking,x,turn)
				elif event.key == pygame.K_7:
						x = 300
						lineChecking = line7
						turn = checkLine(lineChecking,x,turn)
				elif event.key == pygame.K_0:
						pygame.draw.rect(screen, (0,0,0), (0,0,350,300))
						initScreen()
						line1 = [0,0,0,0,0,0]
						line2 = [0,0,0,0,0,0]
						line3 = [0,0,0,0,0,0]
						line4 = [0,0,0,0,0,0]
						line5 = [0,0,0,0,0,0]
						line6 = [0,0,0,0,0,0]
						line7 = [0,0,0,0,0,0]
						turn = 0
						

			if event.type == pygame.QUIT:
				running = False
				print("Bye!")

main()
