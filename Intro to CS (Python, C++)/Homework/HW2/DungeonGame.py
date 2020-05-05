# Assignment #2: Create a dungeon game
# Name: Dominic B
# Date: 8/30/15

print("Welcome to Dominic's dungeon!")

currentRoom = "kitchen"
doors = ("There are doors to the west (w), south (s) and east (e).")
direction = ""

while direction != "q":
	if currentRoom == "kitchen":
		print("You are in the kitchen.")
		direction = input(doors)
	
	if direction == "s": 
		currentRoom = "furnace"
		print("You enter the furance and fry yourself to death!")
		direction = "q"

	elif direction == "e":
		currentRoom = "livingRoom"
		while currentRoom == "livingRoom":		
			print("You are in the living room.")
			direction = input(doors)
			
			if direction == "w": 
				currentRoom = "kitchen"

	elif direction == "w": 
		currentRoom = "hallway"
		while currentRoom == "hallway":
			print("You are in the hallway.")
			direction = input(doors)
			if direction == "e": 
				currentRoom = "kitchen"
			elif direction == "n": 
				currentRoom = "secret"
				while currentRoom == "secret":
					print("You have discovered a secret passage!")
					direction = input("You can continue north (n) or return to the hallway (s).")
					if direction == "s": 
						currentRoom = "hallway"
					if direction == "n": 
						currentRoom = "secretRoom"
						while currentRoom == "secretRoom" and direction != "q":
							print("You have discovered a secret room!")
							direction = input("No more to see press (s) to go back.")
							if direction == "s":
								currentRoom = "secret"
							elif direction == "e":
								print("You found another hidden door! You walk through and fall to your death!")
								direction = "q"
							elif direction == "n":
								print("You found another hidden door! You walk through and are stabbed through the heart!")
								direction = "q"
							elif direction == "w":
								print("You found another hidden door! You walk through and are teleported to the furnace where you are incinerated!")
								direction = "q"
			elif direction == "s":
				currentRoom = "library"
				while currentRoom == "library" and direction != "q":
					direction = input("You are in the library. You sense the princess is here, but where? Look around (l)")
					if direction == "n":
						currentRoom = "hallway"
					elif direction == "l":
						direction = input("You look, and see a picture (p), bookcase (b), closet(c)")
						if direction == "p":
							print("You look at the picture, and see the princess hiding in it! You are a hero!")
							direction = "q"
						elif direction == "b":
							direction = input("You look through the bookcase, and see your Python textbook.")
						elif direction == "c":
							direction = input("You look through the closet, and you find SKELETONS!")
						elif direction == "n":
							currentRoom = "hallway"
	

# Goodbye for exit
if direction == "q":
	print("Goodbye!")
