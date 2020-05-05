# Name: Dominic B
# Date: 9/28/15
# Program: Pong Game
# Description: A simple game of pong using PyGame

import pygame
pygame.init()

score1 = 0
score2 = 0

p1y = 50

size = [800,500]
screen = pygame.display.set_mode(size)

pygame.display.set_caption("Pong")

p2 = pygame.draw.rect(screen, (225,225,255), (750,50,20,100),1)

p1 = pygame.draw.rect(screen, (225,225,255), (30,p1y,20,100))

def initScreen(): #Initialize the game
	pygame.draw.line(screen, (225,225,255), (400,0), (400,500))
		
	myfont = pygame.font.SysFont("helvetica", 50)
		
	num1 = myfont.render("0", 1, (255,255,255))
	screen.blit(num1, (200, 20))

	num2 = myfont.render("0", 1, (255,255,255))
	screen.blit(num2, (600, 20))
	pygame.display.flip()

def draw1(p1y,p1): #Draw player 1 paddle
	p1 = pygame.draw.rect(screen, (225,225,255), (30,p1y,20,100))
	pygame.display.flip()
	return(p1y)
def black1():
	p1 = pygame.draw.rect(screen, (0,0,0), (30,p1y,20,100))
	pygame.display.flip()

def main():
	initScreen()

	running = True

	while running:
		p1y = 50
						
		for event in pygame.event.get():
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_w:
					black1()
					p1y -= 1
					#p1.move_ip(30,100)
					draw1(p1y,p1)
			if event.type == pygame.QUIT:
				running = False

main()
