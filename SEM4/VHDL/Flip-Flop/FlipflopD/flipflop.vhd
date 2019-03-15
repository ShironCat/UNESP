LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY flipflop IS 
	PORT ( 
		I : IN STD_LOGIC;
		clk: IN STD_LOGIC;
		enable : IN STD_LOGIC;
		O : OUT STD_LOGIC
	);
END flipflop;
ARCHITECTURE flipflopBehaviour OF flipflop IS
signal Q:  STD_LOGIC;
BEGIN	
	PROCESS( clk )
	BEGIN	
		IF clk'EVENT AND clk = '1' AND enable = '1' THEN
			Q <= I;
		ELSE
			Q <= Q;
		END IF;
	END PROCESS;
	O <= Q;
END flipflopBehaviour;