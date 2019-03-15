LIBRARY ieee;
USE ieee.std_logic_1164.all;

ENTITY flipflopD IS
	PORT (iSW: IN STD_LOGIC_VECTOR (0 downto 0);
			iKEY: IN STD_LOGIC_VECTOR (0 downto 0);
			oLEDR : OUT STD_LOGIC_VECTOR (0 downto 0)
	);
END flipflopD;

ARCHITECTURE flipflopDbehavior OF flipflopD IS
SIGNAL QB: STD_LOGIC;
BEGIN
	PROCESS( iKEY(0) )
	BEGIN
		IF iKEY(0)'EVENT AND iKEY(0) = '1' THEN
			IF iSW(0) = '0' THEN
				QB<=QB;
			ELSIF iSW(0) = '1' THEN
				QB <= NOT(QB);
			END IF;
		END IF;
	END PROCESS;
	oLEDR(0)<=QB;
END flipflopDbehavior;