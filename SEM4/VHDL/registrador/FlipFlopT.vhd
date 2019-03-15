LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY flipflopT IS
	PORT (  iSW:   IN STD_LOGIC;
			iKEY:   IN STD_LOGIC_VECTOR(0 downto 0);
			iSW1:   IN STD_LOGIC;
			oLEDR : OUT STD_LOGIC
	);
END flipflopT;

ARCHITECTURE flipflopTbehavior OF flipflopT IS
SIGNAL QB: STD_LOGIC;
BEGIN
	PROCESS( iKEY(0) )
	BEGIN
		IF iKEY(0)'EVENT AND iKEY(0) = '1' AND iSW1 = '1' THEN
			IF iSW = '0' THEN
				QB<= QB;
			ELSIF iSW = '1' THEN
				QB <= NOT QB;
			END IF;
		ELSIF iKEY(0)'EVENT AND iKEY(0) = '1' AND iSW1  = '0' THEN	
			QB <= '0';
		END IF;
	END PROCESS;
	oLEDR<=QB;
END flipflopTbehavior;