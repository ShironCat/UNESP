LIBRARY ieee;
USE ieee.std_logic_1164.all;

entity controlador is
	port(
		iCLK    : IN STD_LOGIC;
		oHEX2_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX2_DP: OUT STD_LOGIC;
		oHEX3_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX3_DP: OUT STD_LOGIC;
		oHEX4_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX4_DP: OUT STD_LOGIC;
		oHEX5_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX5_DP: OUT STD_LOGIC;
		oHEX6_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX6_DP: OUT STD_LOGIC;
		oHEX7_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX7_DP: OUT STD_LOGIC
	);
end controlador;

architecture controladorCircuito of controlador is
	COMPONENT contador IS
	PORT(
		iSW :   IN STD_LOGIC_VECTOR (1 downto 0);
		iKEY :   IN STD_LOGIC_VECTOR (0 downto 0);
		oHEX0_D : OUT STD_LOGIC_VECTOR (6 downto 0);
		oHEX0_DP : OUT STD_LOGIC
	);
	END COMPONENT;
	signal segundoU : integer := 0;
	signal segundoD : integer := 0;
	signal minutoU : integer := 0;
	signal minutoD : integer := 0;
	signal horaU : integer := 0;
	signal horaD : integer := 0;
	signal resto: std_logic_vector(5 downto 0);
	signal entrada: std_logic_vector( 11 downto 0 );
begin
	process (iCLK)
	begin
		if iCLK'event and iCLK = '1' then
			segundoU <= segundoU + 1;
			if segundoU = 10 then
				resto(0) <= '1';
				segundoU <= 0;
				segundoD <= segundoD + 1;
				if segundoD = 6 then
					resto(1) <= '1';
					segundoD <= 0;
					minutoU <= minutoU + 1;
					if minutoU = 10 then
						resto(2) <= '1';
						minutoU <= 0;
						minutoD <= minutoD+1;
						if minutoD = 6 then
							resto(3) <= '1';
							minutoD <= 0;
							horaU <= horaU+1;
							if horaU = 10 then
								resto(4) <= '1';
								horaU<= 0;
								horaD <= horaD+1;
								if horaD = 2 and horaU = 4 then
									resto(5) <= '1';
									horaD <= 0;
									horaU <= 0;
								else
									resto(5) <= '0';
								end if;
							else
								resto(4) <= '0';
							end if;
						else
							resto(3) <= '0';
						end if;
					else
						resto(2) <= '0';
					end if;
				else
					resto(1) <= '0';
				end if;
			else
				resto(0) <= '0';
			end if;
		end if;
	end process;

	entrada(0) <= iCLK;
	entrada(1) <= resto(0);
	cont1 : contador port map ( entrada( 1 downto 0), entrada(0 downto 0), oHEX2_D(6 downto 0), oHEX2_DP );
	
	entrada(2) <= resto(0);
	entrada(3) <= resto(1);
	cont2 : contador port map ( entrada( 3 downto 2), resto(0 downto 0), oHEX3_D(6 downto 0), oHEX3_DP );
	
	entrada(4) <= resto(1);
	entrada(5) <= resto(2);
	cont3 : contador port map ( entrada( 5 downto 4), resto(1 downto 1), oHEX4_D(6 downto 0), oHEX4_DP );
	
	entrada(6) <= resto(2);
	entrada(7) <= resto(3);
	cont4 : contador port map ( entrada( 7 downto 6), resto(2 downto 2), oHEX5_D(6 downto 0), oHEX5_DP );
	
	entrada(8) <= resto(3);
	entrada(9) <= resto(4);
	cont5 : contador port map ( entrada( 9 downto 8), resto(3 downto 3), oHEX6_D(6 downto 0), oHEX6_DP );
	
	entrada(10) <= resto(4);
	entrada(11) <= resto(5);
	cont6 : contador port map ( entrada( 11 downto 10), resto(4 downto 4), oHEX7_D(6 downto 0), oHEX7_DP );
	
end controladorCircuito;