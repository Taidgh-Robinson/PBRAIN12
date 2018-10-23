#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int OP0 (char *);
int OP1 (char *);
int OP2 (char *);
int OP3 (char *);
int OP4 (char *);
int OP5 (char *);
int OP6 (char *);
int OP7 (char *);
int OP8 (char *);
int OP9 (char *);
int OP10 (char *);
int OP11 (char *);
int OP12 (char *);
int OP13 (char *);
int OP14 (char *);
int OP15 (char *);
int OP16 (char *);
int OP17 (char *);
int OP18 (char *);
int OP19 (char *);
int OP20 (char *);
int OP21 (char *);
int OP22 (char *);
int OP23 (char *);
int OP24 (char *IR, char *PSW);
int OP25 (char *IR, char *PSW);
int OP26 (char *IR, char *PSW);
int OP27 (char *IR, char *PSW);
int OP28 (char *IR, char *PSW);
int OP29 (char *IR, char *PSW);
int OP30 (char *IR, char *PSW);
int OP31 (char *IR, char *PSW);
int OP32 (char *IR, char *PSW);
int OP33 (char *IR, char *PSW, short int *PC);
int OP34 (char *IR, char *PSW, short int *PC);
int OP35 (char *IR, short int *PC);

int StoreData (int Memory_Location, int Value);
void PrintIR (char *IR);
void printMEM ();
int FetchData (int);
int charValueToInt (char opcode);
int ParseOp1 (char *IR);
int ParseOp2 (char *IR);
int ParseOp1andOp2Imm (char *IR);
int ParseOp1Reg (char *IR);
int ParseOp2Reg (char *IR);

/*These variables are associated with the implementation of the VM*/
int fp;
int i;
int j, k;
char input_line[7];

/*These are variables representing the VM itself*/

char IR[6];
short int PC = 0;

short int P0;			//these are the pointer registers
short int P1;
short int P2;
short int P3;

int R0;				//GP regs
int R1;
int R2;
int R3;

int ACC;
char PSW[2];
char memory[100][6];		//this is the program memory for first program
short int opcode;		//nice to know what we are doing
int program_line = 0;
int upto = 0;

int
main (int argc, char *argv[])
{

  //Step 1 Read file into VM memory. Assume the file name is program2.

  fp = open ("program2", O_RDONLY);	//always check the return value. 
  printf ("Open is %d \n", fp);

  if (fp < 0)			//error in read 
    {
      printf ("Could not open file");
      exit (0);
    }


  //read in the first line of the program

  int ret = read (fp, input_line, 7);	//returns number of characters read

  while (1)
    {
      if (ret <= 0)		//indicates end of file or error
	break;			//breaks out of infinite loop

      //copy from input line into program memory

      printf ("Copying Program line %d into memory \n", program_line);

      for (i = 0; i < 6; i++)
	{
	  memory[program_line][i] = input_line[i];
	  printf ("%c", memory[program_line][i]);
	}

      printf ("\n");

      //read in next line of code

      ret = read (fp, input_line, 7);
      program_line++;		//now at a new line in the prog
    }
  upto = program_line;
  printf ("PROGRAM COPIED INTO VM MEMORY!! \n");

  //Now we are ready to execute instructions! Yehawwww!

  int Done = 0;
  PC = 0;			//program counter, always starts at 0

  while (!Done)
    {
      //first place the instruction into the instruction register
      for (i = 0; i < 6; i++)
	IR[i] = memory[PC][i];

      printf ("IR: %s \n", IR);

      opcode = ((int) (IR[0]) - 48) * 10;
      opcode += ((int) (IR[1]) - 48);

      printf ("In Program Execution Loop: New PC is %d OPCODE IS %d \n\n", PC,
	      opcode);

      /* You need to put in the case statements for the remaining opcodes */

      switch (opcode)
	{
	case 0:
	  OP0 (IR);
	  PC++;
	  break;
	case 1:
	  OP1 (IR);
	  PC++;
	  break;
	case 2:
	  OP2 (IR);
	  PC++;
	  break;
	case 3:
	  OP3 (IR);
	  PC++;
	  break;
	case 4:
	  OP4 (IR);
	  PC++;
	  break;
	case 5:
	  OP5 (IR);
	  PC++;
	  break;
	case 6:
	  OP6 (IR);
	  PC++;
	  break;
	case 7:
	  OP7 (IR);
	  PC++;
	  break;
	case 8:
	  OP8 (IR);
	  PC++;
	  break;
	case 9:
	  OP9 (IR);
	  PC++;
	  break;
	case 10:
	  OP10 (IR);
	  PC++;
	  break;
	case 11:
	  OP11 (IR);
	  PC++;
	  break;
	case 12:
	  OP12 (IR);
	  PC++;
	  break;
	case 13:
	  OP13 (IR);
	  PC++;
	  break;
	case 14:
	  OP14 (IR);
	  PC++;
	  break;
	case 15:
	  OP15 (IR);
	  PC++;
	  break;
	case 16:
	  OP16 (IR);
	  PC++;
	  break;
	case 17:
	  OP17 (IR);
	  PC++;
	  break;
	case 18:
	  OP18 (IR);
	  PC++;
	  break;
	case 19:
	  OP19 (IR);
	  PC++;
	  break;
	case 20:
	  OP20 (IR);
	  PC++;
	  break;
	case 21:
	  OP21 (IR);
	  PC++;
	  break;
	case 22:
	  OP22 (IR);
	  PC++;
	  break;
	case 23:
	  OP23 (IR);
	  PC++;
	  break;
	case 24:
	  OP24 (IR, PSW);
	  PC++;
	  break;
	case 25:
	  OP25 (IR, PSW);
	  PC++;
	  break;
	case 26:
	  OP26 (IR, PSW);
	  PC++;
	  break;
	case 27:
	  OP27 (IR, PSW);
	  PC++;
	  break;
	case 28:
	  OP28 (IR, PSW);
	  PC++;
	  break;
	case 29:
	  OP29 (IR, PSW);
	  PC++;
	  break;
	case 30:
	  OP30 (IR, PSW);
	  PC++;
	  break;
	case 31:
	  OP31 (IR, PSW);
	  PC++;
	  break;
	case 32:
	  OP32 (IR, PSW);
	  PC++;
	  break;
	case 33:
	  OP33 (IR, PSW, &PC);
	  break;
	case 34:
	  OP34 (IR, PSW, &PC);
	  break;
	case 35:
	  OP35 (IR, &PC);
	  break;
	case 99:
	  printf ("ALL DONE \n");
	  Done = 1;
	  break;
	default:
	  printf ("Instruction %d not found!~ \n", opcode);
	  exit (0);
	}

	printf("MACHINE STATE: ACC = [%d], P0 = [%d], P1 = [%d], P2 = [%d], P3 = [%d], R0 = [%d], R1 = [%d], R2 = [%d], R3 = [%d] \n \n \n", ACC, P0, P1, P2, P3, R0, R1, R2, R3);
    }

  printMEM (upto+1);

}

//Now its time for the instruction execution functions.
// Here is the first.

int
OP0 (char *IR)
{
  int PREG, VAL;
  printf ("Opcode = 0. Load Pointer Immediate \n");

  PREG = ParseOp1Reg (IR);
  VAL = ParseOp2 (IR);

  switch (PREG)
    {
    case 0:
      P0 = VAL;
    case 1:
      P1 = VAL;
    case 2:
      P2 = VAL;
    case 3:
      P3 = VAL;
    }

  //Will print out junk until the two helper functions are implemented!
  printf ("Loaded P[%d] with immediate value %d \n", PREG, VAL);
}

int
OP1 (char *IR)
{

  printf ("Opcode = 1. Add To Pointer Immediate \n");
  int PREG, VAL;

  PREG = ParseOp1Reg (IR);
  VAL = ParseOp2 (IR);

  switch (PREG)
    {
    case 0:
      P0 += VAL;
      break;
    case 1:
      P1 += VAL;
      break;
    case 2:
      P2 += VAL;
      break;
    case 3:
      P3 += VAL;
      break;
    }

  printf ("Incremented P[%d] with immediate value %d \n", PREG, VAL);
}

int
OP2 (char *IR)
{

  printf ("Opcode = 2. Add To Pointer Immediate \n");
  int PREG, VAL;

  PREG = ParseOp1Reg (IR);
  VAL = ParseOp2 (IR);

  switch (PREG)
    {
    case 0:
      P0 -= VAL;
      break;
    case 1:
      P1 -= VAL;
      break;
    case 2:
      P2 -= VAL;
      break;
    case 3:
      P3 -= VAL;
      break;
    }

  printf ("Decremented P[%d] with immediate value %d \n", PREG, VAL);
}

int
OP3 (char *IR)
{

  printf ("Opcode = 3. Load Accumulator Immediate \n");
  ACC = ParseOp1andOp2Imm (IR);
  printf ("Loaded ACC with value %d \n", ParseOp1andOp2Imm (IR));

}

int
OP4 (char *IR)
{
  printf ("Opcode = 4. Load Accumulator Register Addressing \n");
  int PREG, VAL;

  PREG = ParseOp1Reg (IR);


  switch (PREG)
    {
    case 0:
      VAL = FetchData (P0);
      break;
    case 1:
      VAL = FetchData (P1);
      break;
    case 2:
      VAL = FetchData (P2);
      break;
    case 3:
      VAL = FetchData (P3);
      break;
    }

  ACC = VAL;

  printf ("ACC was set to %d \n", VAL);
}

int
OP5 (char *IR)
{

  printf ("Opcode = 5. Load Accumulator Direct Addressing \n");
  int location;

  location = ParseOp1 (IR);
  ACC = FetchData (location);

  printf ("ACC was set to %d which was stored in the memory location %d \n",
	  ACC, location);


}

int
OP6 (char *IR)
{

  printf ("Opcode = 6. Store Accumulator Register Addressing \n");
  int PREG = ParseOp1Reg (IR);
  switch (PREG)
    {
    case 0:
      StoreData (P0, ACC);
      break;
    case 1:
      StoreData (P1, ACC);
      break;
    case 2:
      StoreData (P2, ACC);
      break;
    case 3:
      StoreData (P3, ACC);
      break;
    }
  printf
    ("Stored the acc value of %d in the memory adress pointed to in P[%d] \n",
     ACC, PREG);

}

int
OP7 (char *IR)
{

  printf ("Opcode = 7. Store Accumulator Direct Addressing \n");
  int location;

  location = ParseOp1 (IR);

  StoreData (location, ACC);

  printf
    ("Stored the acc value of %d in the memory adress pointed to in memory location %d \n",
     ACC, location);
}

int
OP8 (char *IR)
{
  printf ("Opcode = 8. Store Register to memory: Register Addressing \n");

  int REG, PREG, VAL, location;
  REG = ParseOp1Reg (IR);
  PREG = ParseOp2Reg (IR);
  switch (REG)
    {
    case 0:
      VAL = R0;
      break; 
   case 1:
      VAL = R1;
      break;
    case 2:
      VAL = R2;
      break;
    case 3:
      VAL = R3;
      break;
    }
  switch (PREG)
    {
    case 0:
      location = P0;
      break;
    case 1:
      location = P1;
      break;
    case 2:
      location = P2;
      break;
    case 3:
      location = P3;
      break;
    }

  StoreData (location, VAL);
  printf
    ("Stored the value %d held in R[%d] in the location %d pointed to by P[%d] \n",
     VAL, REG, location, PREG);

}

int
OP9 (char *IR)
{

  printf ("Opcode = 9. Store Register to Memory: Direct Addressing \n");

  int REG, VAL, location;

  REG = ParseOp1Reg (IR);
  location = ParseOp2 (IR);

  switch (REG)
    {
    case 0:
      VAL = R0;
      break;
    case 1:
      VAL = R1;
      break;
    case 2:
      VAL = R2;
      break;
    case 3:
      VAL = R3;
      break;
    }

  StoreData (location, VAL);

  printf ("The value %d help in R[%d] was stored in Memory loction %d \n", VAL,
	  REG, location);


}

int
OP10 (char *IR)
{

  printf ("Opcode = 10. Load Register from memory: Register Addressing \n");

  int REG, PREG, VAL, location;
  REG = ParseOp1Reg (IR);
  PREG = ParseOp2Reg (IR);

  switch (PREG)
    {
    case 0:
      location = P0;
      break;
    case 1:
      location = P1;
      break;
    case 2:
      location = P2;
      break;
    case 3:
      location = P3;
      break;
    }

  VAL = FetchData (location);

  switch (REG)
    {
    case 0:
      R0 = VAL;
      break;
    case 1:
      R1 = VAL;
      break;
    case 2:
      R2 = VAL;
      break;
    case 3:
      R3 = VAL;
      break;
    }


  printf
    ("Stored the value %d in the location %d pointed to by P[%d] to R[%d] \n",
     VAL, location, PREG, REG);


}

int
OP11 (char *IR)
{

  printf ("Opcode = 11. Load register from memory: Direct Addressing \n");
  int REG, location, VAL;

  REG = ParseOp1Reg (IR);
  location = ParseOp2 (IR);
  VAL = FetchData (location);

  switch (REG)
    {
    case 0:
      R0 = VAL;
      break;
    case 1:
      R1 = VAL;
      break;
    case 2:
      R2 = VAL;
      break;
    case 3:
      R3 = VAL;
      break;
    }

  printf ("Set R[%d] to %d which was stored in memory location %d \n", REG,
	  VAL, location);

}

int
OP12 (char *IR)
{
  printf ("Opcode = 12. Load Register R0 Immediate \n");
  int VAL = ParseOp1andOp2Imm (IR);
  R0 = VAL;
  printf ("R0 set to %d \n", VAL);

}

int
OP13 (char *IR)
{
  printf ("Opcode = 13. Register to Register Transfer \n");
  int TREG, SREG, VAL;
  TREG = ParseOp1Reg (IR);
  SREG = ParseOp2Reg (IR);

  switch (SREG)
    {
    case 0:
      VAL = R0;
      break;
    case 1:
      VAL = R1;
      break;
    case 2:
      VAL = R2;
      break;
    case 3:
      VAL = R3;
      break;
    }

  switch (TREG)
    {
    case 0:
      TREG = VAL;
      break;
    case 1:
      TREG = VAL;
      break;
    case 2:
      TREG = VAL;
      break;
    case 3:
      TREG = VAL;
      break;
    }

  printf ("Value %d was moved from R[%d] to R[%d] \n", VAL, SREG, TREG);



}

int
OP14 (char *IR)
{

  printf ("Opcode = 14. Load Accumulator from Register \n");
  int REG = ParseOp1Reg (IR);
  switch (REG)
    {
    case 0:
      ACC = R0;
      break;
    case 1:
      ACC = R1;
      break;
    case 2:
      ACC = R2;
      break;
    case 3:
      ACC = R3;
      break;
    }

  printf ("Loaded ACC with R[%d] \n", REG);

}




int
OP15 (char *IR)
{

  printf ("Opcode = 15. Load Register from Accumulator \n");
  int REG = ParseOp1Reg (IR);
  switch (REG)
    {
    case 0:
      R0 = ACC;
      break;
    case 1:
      R1 = ACC;
      break;
    case 2:
      R2 = ACC;
      break;
    case 3:
      R3 = ACC;
      break;
    }

  printf ("Loaded R[%d] with acc value %d \n", REG, ACC);

}

int
OP16 (char *IR)
{

  printf ("Opcode = 16. Add Accumulator Immediate \n");
  int VAL = ParseOp1andOp2Imm (IR);
  ACC += VAL;
  printf ("ACC was incremented by %d to %d \n", VAL, ACC);

}

int
OP17 (char *IR)
{

  printf ("Opcode = 17. Subtract Accumulator Immediate \n");
  int VAL = ParseOp1andOp2Imm (IR);
  ACC -= VAL;
  printf ("ACC was decremented by %d to %d \n", VAL, ACC);

}

int
OP18 (char *IR)
{
  printf ("Opcode = 17. Add contents of Register to Accumulator \n");

  int REG, VAL;
  REG = ParseOp1Reg (IR);
  switch (REG)
    {
    case 0:
      VAL = R0;
      break;
    case 1:
      VAL = R1;
      break;
    case 2:
      VAL = R2;
      break;
    case 3:
      VAL = R3;
      break;
    }

  ACC += VAL;

  printf ("ACC was incremented by %d held in R[%d] to %d \n", VAL, REG, ACC);

}

int
OP19 (char *IR)
{
  printf ("Opcode = 19. Subtract contents of Register to Accumulator \n");

  int REG, VAL;
  REG = ParseOp1Reg (IR);
  switch (REG)
    {
    case 0:
      VAL = R0;
      break;
    case 1:
      VAL = R1;
      break;
    case 2:
      VAL = R2;
      break;
    case 3:
      VAL = R3;
      break;
    }

  ACC -= VAL;

  printf ("ACC was decremented by %d held in R[%d] to %d \n", VAL, REG, ACC);

}

int
OP20 (char *IR)
{

  printf ("Opcode = 20. Add Accumulator Register Addressing. \n");
  int PREG, VAL;

  PREG = ParseOp1Reg (IR);


  switch (PREG)
    {
    case 0:
      VAL = FetchData (P0);
      break;
    case 1:
      VAL = FetchData (P1);
      break;
    case 2:
      VAL = FetchData (P2);
      break;
    case 3:
      VAL = FetchData (P3);
      break;
    }

  ACC += VAL;

  printf ("ACC was incremented by %d to %d \n", VAL, ACC);
}

int
OP21 (char *IR)
{
  printf ("Opcode = 21. Add Accumulator Direct Addressing. \n");
  int VAL, location;
  location = ParseOp1 (IR);
  VAL = FetchData (location);
  ACC += VAL;
  printf
    ("Value %d was fetched from location %d and added to the ACC which is now %d \n",
     VAL, location, ACC);

}

int
OP22 (char *IR)
{

  printf ("Opcode = 22. Subtract Accumulator Register Addressing. \n");
  int PREG, VAL;

  PREG = ParseOp1Reg (IR);


  switch (PREG)
    {
    case 0:
      VAL = FetchData (P0);
      break;
    case 1:
      VAL = FetchData (P1);
      break;
    case 2:
      VAL = FetchData (P2);
      break;
    case 3:
      VAL = FetchData (P3);
      break;
    }

  ACC -= VAL;

  printf ("ACC was decremented by %d to %d \n", VAL, ACC);
}

int
OP23 (char *IR)
{
  printf ("Opcode = 23. Add Accumulator Direct Addressing. \n");
  int VAL, location;
  location = ParseOp1 (IR);
  VAL = FetchData (location);
  ACC -= VAL;
  printf
    ("Value %d was fetched from location %d and subracted from the ACC which is now %d \n",
     VAL, location, ACC);

}

int
OP24 (char *IR, char *PSW)
{

  printf ("Opcode = 24. Compare Equal Register Addressing \n");

  int PREG, VAL;
  PREG = ParseOp1Reg (IR);

  switch (PREG)
    {
    case 0:
      VAL = FetchData (P0);
      break;
    case 1:
      VAL = FetchData (P1);
      break;
    case 2:
      VAL = FetchData (P2);
      break;
    case 3:
      VAL = FetchData (P3);
      break;
    }

  if (ACC == VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, P[%d]: %d, PSW[0] was set to %c \n", ACC, PREG, VAL,
	  PSW[0]);

}

int
OP25 (char *IR, char *PSW)
{

  printf ("Opcode = 25. Compare Less Register Addressing \n");

  int PREG, VAL;
  PREG = ParseOp1Reg (IR);

  switch (PREG)
    {
    case 0:
      VAL = FetchData (P0);
      break;
    case 1:
      VAL = FetchData (P1);
      break;
    case 2:
      VAL = FetchData (P2);
      break;
    case 3:
      VAL = FetchData (P3);
      break;
    }

  if (ACC < VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, P[%d]: %d, PSW[0] was set to %c \n", ACC, PREG, VAL,
	  PSW[0]);

}


int
OP26 (char *IR, char *PSW)
{

  printf ("Opcode = 26. Compare Greater Register Addressing \n");

  int PREG, VAL;
  PREG = ParseOp1Reg (IR);

  switch (PREG)
    {
    case 0:
      VAL = FetchData (P0);
      break;
    case 1:
      VAL = FetchData (P1);
      break;
    case 2:
      VAL = FetchData (P2);
      break;
    case 3:
      VAL = FetchData (P3);
      break;
    }

  if (ACC > VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, P[%d]: %d, PSW[0] was set to %c \n", ACC, PREG, VAL,
	  PSW[0]);

}

int
OP27 (char *IR, char *PSW)
{
  printf ("Opcode = 27. Compare Greater Immediate \n");

  int VAL = ParseOp1andOp2Imm (IR);
  if (ACC > VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, Immediate Vale: %d, PSW[0] updated to %c \n", ACC, VAL,
	  PSW[0]);


}

int
OP28 (char *IR, char *PSW)
{
  printf ("Opcode = 28. Compare Equal Immediate \n");

  int VAL = ParseOp1andOp2Imm (IR);
  if (ACC == VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, Immediate Vale: %d, PSW[0] updated to %c \n", ACC, VAL,
	  PSW[0]);


}

int
OP29 (char *IR, char *PSW)
{
  printf ("Opcode = 29. Compare Less Immediate \n");

  int VAL = ParseOp1andOp2Imm (IR);
  if (ACC < VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, Immediate Vale: %d, PSW[0] updated to %c \n", ACC, VAL,
	  PSW[0]);


}

int
OP30 (char *IR, char *PSW)
{

  printf ("Opcode = 30. Compare Register Equal \n");

  int REG, VAL;

  REG = ParseOp1Reg (IR);

  switch (REG)
    {
    case 0:
      VAL = R0;
      break;
    case 1:
      VAL = R1;
      break;
    case 2:
      VAL = R2;
      break;
    case 3:
      VAL = R3;
      break;
    }

  if (ACC == VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, R[%d]: %d, PSW[0] was set to %c \n", ACC, REG, VAL, PSW[0]);

}

int
OP31 (char *IR, char *PSW)
{

  printf ("Opcode = 31. Compare Register Less \n");

  int REG, VAL;

  REG = ParseOp1Reg (IR);

  switch (REG)
    {
    case 0:
      VAL = R0;
      break;
    case 1:
      VAL = R1;
      break;
    case 2:
      VAL = R2;
      break;
    case 3:
      VAL = R3;
      break;
    }

  if (ACC < VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, R[%d]: %d, PSW[0] was set to %c \n", ACC, REG, VAL, PSW[0]);

}

int
OP32 (char *IR, char *PSW)
{

  printf ("Opcode = 32. Compare Register Greater \n");

  int REG, VAL;

  REG = ParseOp1Reg (IR);

  switch (REG)
    {
    case 0:
      VAL = R0;
      break;
    case 1:
      VAL = R1;
      break;
    case 2:
      VAL = R2;
      break;
    case 3:
      VAL = R3;
      break;
    }

  if (ACC > VAL)
    {
      PSW[0] = 'T';
    }
  else
    {
      PSW[0] = 'F';
    }

  printf ("ACC: %d, R[%d]: %d, PSW[0] was set to %c \n", ACC, REG, VAL, PSW[0]);

}

int
OP33 (char *IR, char *PSW, short int *PC)
{

  printf ("Opcode = 33. Branch Conditional True \n");

  if (PSW[0] == 'T')
    {

      *PC = ParseOp1 (IR);

    }
  else
    {

      *PC += 1;

    }

  printf ("PSW[0] was %c, PC was set to %d \n", PSW[0], *PC);

}

int
OP34 (char *IR, char *PSW, short int *PC)
{

  printf ("Opcode = 34. Branch Conditional False\n");

  if (PSW[0] == 'F')
    {

      *PC = ParseOp1 (IR);

    }
  else
    {

      *PC += 1;

    }

  printf ("PSW[0] was %c, PC was set to %d \n", PSW[0], *PC);

}

int
OP35 (char *IR, short int *PC)
{

  int val = ParseOp1 (IR);
  printf ("Opcode = 35. Branch Unconditional \n");
  *PC = val;
  printf ("PC has been set to %d \n", val);


}

//HELPER FUNCTIONS

int
charValueToInt (char opcode)
{

  return (int) opcode - 48;

}

//This function returns the integer value of operand 1 
//when this operand is an immediate two-byte integer. 

int
ParseOp1 (char *IR)
{

  return charValueToInt (IR[2]) * 10 + charValueToInt (IR[3]);

}

// returns the integer value of operand 2 when this operand is a two-byte integer. 
int
ParseOp2 (char *IR)
{

  return charValueToInt (IR[4]) * 10 + charValueToInt (IR[5]);

}

//returns the integer value of operands 1 and 2 combined to form a 4-byte integer.
int
ParseOp1andOp2Imm (char *IR)
{

  return charValueToInt (IR[2]) * 1000 + charValueToInt (IR[3]) * 100 +
    charValueToInt (IR[4]) * 10 + charValueToInt (IR[5]);

}

// returns the register number of the register used as operand  1 of an instruction. 
// Can be either Pointer or General-Purpose register. 
int
ParseOp1Reg (char *IR)
{

  return charValueToInt (IR[3]);

}

// returns the register number of a register used as operand  2 of an instruction. 
// Can be either a Pointer or General-Purpose register. 
int
ParseOp2Reg (char *IR)
{

  return charValueToInt (IR[5]);

}

// returns the data stored at memory location Memory_Location
int
FetchData (int Memory_Location)
{
  char *temp = &memory[Memory_Location][2];
  return (atoi (temp));

}


//Prints out the contents of the IR on the same line.
void
PrintIR (char *IR)
{

  printf ("%s \n", IR);

}

//Converts Value from an int to a character string and stores it in memory[Memory_Location]
int
StoreData (int Memory_Location, int Value)
{
  if (Memory_Location > upto){
    upto = Memory_Location;
  }
  int tmp = Value;
  memory[Memory_Location][0] = 'Z';
  memory[Memory_Location][1] = 'Z';

  if(Value < 1){
    memory[Memory_Location][5] = '0';
  }else{memory[Memory_Location][5] = (tmp % 10) + '0';}
  tmp /= 10;

  if(Value < 10){
    memory[Memory_Location][4] = '0';
  }else{memory[Memory_Location][4] = (tmp % 10) + '0';}
  tmp /= 10;
  
  if(Value < 100){
    memory[Memory_Location][3] = '0';
  }else{memory[Memory_Location][3] = (tmp % 10) + '0';}
  tmp /= 10;

  if(Value < 1000){
    memory[Memory_Location][2] = '0';
  }else{memory[Memory_Location][2] = (tmp % 10) + '0';}
  tmp /= 10;

}

//prints out the contents of memory from row 0 to row upto. 
//This should print all instructions and data within 0 - unto.
//Each row of memory should be printed on a separate line.  

void
printMEM (int upto)
{

  for (int i = 0; i < upto; i++)
    {

      printf ("%c %c %c %c %c %c \n", memory[i][0], memory[i][1],
	      memory[i][2], memory[i][3], memory[i][4], memory[i][5]);

    }


}
