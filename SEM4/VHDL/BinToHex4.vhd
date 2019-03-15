LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY BinToHex4 IS
PORT (
	iSW : IN STD_LOGIC_VECTOR(7 DOWNTO 0);
	oHEX0_D : OUT STD_LOGIC_VECTOR(6 DOWNTO 0);
	oHEX0_DP : OUT STD_LOGIC
);
END aula01;

ARCHITECTURE BinToHex4Comportamento OF BinToHex4 IS
SIGNAL A : STD_LOGIC;
SIGNAL B : STD_LOGIC;
SIGNAL C : STD_LOGIC;
SIGNAL D : STD_LOGIC;
BEGIN
	D <= iSW(0);
	C<= iSW(1);
	B <= iSW(2);
	A <= iSW(3);
	
	oHEX0_D(0) <= (NOT A AND NOT B AND NOT C AND D) OR (NOT A AND B AND NOT C AND NOT D) OR (A AND B AND NOT C AND D) OR (A AND NOT B AND C AND D);
	oHEX0_D(1) <= (B AND C AND NOT D) OR (A AND C AND D) OR (NOT A AND B AND NOT C AND D) OR (A AND B AND NOT D);
	oHEX0_D(2) <= (A AND B AND C) OR (A AND B AND NOT D) OR (NOT A AND NOT B AND C AND NOT D);
	oHEX0_D(3) <= (B AND C AND D) OR (NOT A AND NOT B AND NOT C AND D) OR (NOT A AND B AND NOT C AND NOT D) OR (A AND NOT B AND C AND NOT D);
	oHEX0_D(4) <= (NOT A AND D) OR (NOT B AND NOT C AND D) OR (NOT A AND B AND NOT C);
	oHEX0_D(5) <= (NOT A AND C AND D) OR (NOT A AND NOT B AND D) OR (NOT A AND NOT B AND C) OR (A AND B AND NOT C AND D);
	oHEX0_D(6) <= (NOT A AND NOT B AND NOT C) OR (NOT A AND B AND C AND D) OR (A AND B AND NOT C AND NOT D);
	oHEX0_DP <= A OR NOT A;
END BinToHex4Comportamento;