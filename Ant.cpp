#include "Ant.hpp"
#include "Board.hpp"

// Default constructor for Ant(), set variables to default values
Ant::Ant()
{
    row = -1;
    col = -1;
    age = 0;
    isEaten = false;
}

// Ant constructor
Ant::Ant(int r, int c)
{
    row = r;
    col = c;
    age = 0;
    isEaten = false;
}

// Ant Destructor
Ant::~Ant()
{
    // Destructor
}

/*********************************************************************
** Ant::move() moves the ants randomly move up, down, left, or right.
** If the neighboring cell in the selected direction is occupied or
** would move the ant off the grid, then the ant stays in the current cell.
*********************************************************************/
void Ant::move(Critter*** board, int row, int col)
{
    // 1 = RIGHT, 2 = LEFT, 3 = UP, 4 = DOWN
    int direction = rand()% 4 + 1;

    switch (direction)
    {
        case 1:     // Ant moving right
            if((col + 1 >= 0) && (col + 1 < 20))
            {
                if (board.getContents(row, col + 1) == NULL)
                {
                    col += 1;
                    age++;
                }
            }
            break;

        case 2:     // Ant moving left
            if((col - 1 >= 0) && (col - 1 < 20))
            {
                if (board.getContents(row, col - 1) == NULL)
                {
                    col -= 1;
                    age++;
                }
            }
            break;

        case 3:     // Ant moving up
            if((row - 1 >= 0) && (row - 1 < 20))
            {
                if (board.getContents(row - 1, col) == NULL)
                {
                    row -= 1;
                    age++;
                }
            }
            break;

        case 4:     // Ant moving down
            if((row + 1 >= 0) && (row + 1 < 20))
            {
                if(board.getContents(row + 1, col) == NULL)
                {
                    row += 1;
                    age++;
                }
            }
            break;
    }
}

void Ant::breed(Critter*** board)
{

}

//print the type of bug (for use in print board function)
void Ant::printType() {
  std::cout << "ant";
}

  //return a 0 for doodlebug and 1 for ant (for use in movement and eating functions? We may just get rid of this one)
int Ant::returnType() {
  return 1;
}

/* The ants behave according to the following model:
Move: For every time step, the ants randomly move up, down, left, or right. If the neighboring
cell in the selected direction is occupied or would move the ant off the grid, then the ant stays
in the current cell.
Breed: If an ant survives for three time steps (not been eaten by doodlebugs), at the end of the
time step (i.e., after moving) the ant will breed. This is simulated by creating a new ant in an
adjacent (up, down, left, or right) cell that is empty randomly. If the cell that is picked is not empty,
randomly attempt to pick another one.  If there is no empty cell available, no breeding occurs.
Once an offspring is produced, an ant cannot produce an offspring again until it has
survived three more time steps. */


/*
 * breed is intended to be run at the end of every turn. If both a pending breeding exists and an adjacent square exists,
 * it will randomly select a direction to spawn a new ant in. breedingPending is then set to false.
 *
 * If either case is false,the function simply returns without modifying anything and the ant will have an opportunity
 * to breed on it's next turn.
 */
void Ant::breed(Board &b)
{
	if (breedingPending == true && b.doesAdjacentExist() == true)
	{
		int tempDirection;
		bool hasCompleted = false;

		while (hasCompleted == false)
		{
			rand() % 4 + 1 = tempDirection;

			if (tempDirection == 1)
			{
				if (b.getContents(row -1, col) == NULL)
				{
					new Ant(row -1, col);
					hasCompleted = true;
				}
			}

			else if (tempDirection == 2) //Right
			{
				if (b.getContents(row, col + 1) == NULL)
				{
					new Ant(row, col + 1);
					hasCompleted = true;
				}
			}

			else if (tempDirection == 3) //Down
			{
				if (b.getContents(row + 1, col) == NULL)
				{
					new Ant(row + 1, col);
					hasCompleted = true;
				}
			}

			else if (tempDirection == 4) //Left
			{
				if (b.getContents(row, col - 1) == NULL)
				{
					new Ant(row, col - 1);
				}
			}
		}
	}
	else return; //If there is a return, breedingPending will remain true and it will be evaluated again on the next round, giving the ant the opportunity to breed again.
}



/*
 * isReadyToBreed is intended to be run after every turn. It will check to see if the ant's age allows it to breed. If there's already
 * a pending breeding, the if statement will skip over the operation and the function will end.
 */
void Ant::isReadyToBreed()
{
	if (age % 3 == 0 && readyToBreed == false)
	{
		readyToBreed = true;
	}
}
