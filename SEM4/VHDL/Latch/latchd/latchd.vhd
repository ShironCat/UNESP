LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY latchd IS
PORT(
	iSW : IN STD_LOGIC_VECTOR(0 downto 0);
	oLEDR : OUT STD_LOGIC_VECTOR(1 downto 0)
);
END latchd;

ARCHITECTURE latchdbehaviour OF latchd IS
SIGNAL SS: STD_LOGIC;
SIGNAL D : STD_LOGIC;
SIGNAL SR: STD_LOGIC;
BEGIN
	
	D  <= iSW(0);
	
	SS <= D NAND SR;
	SR <= NOT D NAND SS;
	
	oLEDR(0) <= SS;
	oLEDR(1) <= SR;

END latchdbehaviour;