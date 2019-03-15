LIBRARY ieee;
USE ieee.std_logic_1164.all;
ENTITY FlipflopRS IS 
	PORT ( 
		iSW : IN STD_LOGIC_VECTOR(1 downto 0);
		iKEY: IN STD_LOGIC_VECTOR(0 downto 0);
		oLEDR : OUT STD_LOGIC_VECTOR(1 downto 0)
	);
END FlipflopRS;
ARCHITECTURE FlipflopBehaviour OF FlipflopRS IS
	SIGNAL temp: STD_LOGIC_VECTOR( 1 downto 0);
	COMPONENT latchsr IS
		PORT(
			iSW : IN STD_LOGIC_VECTOR(1 downto 0);
			oLEDR : OUT STD_LOGIC_VECTOR(1 downto 0)
		);
	END COMPONENT;
BEGIN
	latch : latchsr port map( temp(1 DOWNTO 0), oLEDR(1 downto 0) );
	
	PROCESS( iKEY(0) )
	BEGIN	
		IF iKEY(0)'EVENT AND iKEY(0) = '1' THEN
			temp <= iSW;
		END IF;
	END PROCESS;
END FlipflopBehaviour;