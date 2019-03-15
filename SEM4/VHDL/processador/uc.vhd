LIBRARY ieee;
USE ieee.std_logic_1164.all;

entity uc is 
	port(
		clk   : in  std_logic;
		estado: in  std_logic;
		ir    : in  std_logic_vector(7 downto 0);
		reg	  : out std_logic_vector(3 downto 0);
		mux	  : out std_logic_vector(3 downto 0);
		ula   : out std_logic_vector(2 downto 0);
		a	  : out std_logic;
		ready : out std_logic
	);
end uc;

architecture controle of uc is
	signal x1 : std_logic_vector(3 downto 0);
	signal x2 : std_logic_vector(2 downto 0);
	signal xa : std_logic;
	signal xu : std_logic_vector(2 downto 0);
	signal xr : std_logic;
	
	begin
		process (clk)
		begin
			if clk'event then
				if estado = "0" then
					xr <= "0";
				end if;
				case ir(7 downto 6) is
					--mov
					when "00" => case estado is
									when "1" => x1(2 downto 0) <= ir(5 downto 3);
											 => x1(3) <= "0";
									when "2" => x2(2 downto 0) <= ir(2 downto 0);
											 => x2(3) <= "1";
									when "3" => x2(3) <= "0";
									when "4" => xr <= "1";
										
								 end case;
					--mvi
					when "01" => case estado is
									when "1" => x1 <= "1001";
									when "2" => x2 <= ir(5 downto 3);
									when "3" => xr <= "1";
								end case;
					--add
					when "10" => case estado is
									when "1" => x1(2 downto 0) <= ir(5 downto 3);
											 => x1(3) <= "0";
									when "2" => xa <= "1";
									when "3" => xa <= "0";
									when "4" => x2 <= ir(2 downto 0);
									when "5" => xu <= "10";
									when "6" => x2 <= ir(5 downto 3);
									when "7" => x1 <= "1000"; 
									when "8" => xr <= "1";
								end case;
					--sub
					when "11" => case estado is
									when "1" => x1(2 downto 0) <= ir(5 downto 3);
											 => x1(3) <= "0";
									when "2" => xa <= "1";
									when "3" => xa <= "0";
									when "4" => x2 <= ir(2 downto 0);
									when "5" => xu <= "11";
									when "6" => x2 <= ir(5 downto 3);
									when "7" => x1 <= "1000"; 
									when "8" => xr <= "1";
								end case;
				end case;
			end if;
		end process;
		mux   <= x1;
		reg   <= x2;
		ula   <= xu;
		a     <= xa;
		ready <= xr;
end controle;