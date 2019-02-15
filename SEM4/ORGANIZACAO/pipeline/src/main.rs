/*
                                		Trabalho de Organização de Computadores
Luiza Torello Vieira
Victor Azadinho Miranda

1 Algoritmo a ser entregue
        Imagine um pipeline o qual você possa desprezar hazards de recursos e de dados. Você deve apenas se 
    preocupar com desvios condicionais. Escreva um programa em uma linguagem de sua preferência que leia um 
    arquivo .txt, o qual contenha um código em assembly de arquitetura 32 bits, e simule um pipeline mediante
    os comandos ali presentes. Seu programa deverá:
        1. Ler um arquivo .txt;
        2. Armazenar as instruções;
        3. Construir um pipeline a partir das instruções lidas;
        4. Mostrar para o usuáio o pipeline.
    O pipeline do seu programa deverá ter 6 est´agios:
        1. Buscar de instrução (FI);
        2. Decodificar instrução (DI);
        3. Calcular operandos (CO);
        4. Obter operandos (FO);
        5. Executar instrução (EI);
        6. Escrever operando (WO).
Entrega: 17/02/2019
*/
extern crate rand;
use rand::{thread_rng, Rng};
use std::io;
use std::fs;

struct Operand {
	name: String,
	value: i32,
	position: u32
}

struct Instruction {
	program_counter: i32,
	buffer: String,
	op_code: i32,
	operand: String //"numero_de_op 	posição_op_1 	posição_op_2"
}

struct Jmp {
	is_jump: bool,
	program_counter: i32
}

//Fetch instruction --> pega a próxima instrução
fn instruction_fetch(program: &Vec<Vec<String>>, program_counter: u32) -> Result<String, String> {
	let mut index = 0;
	for i in program {
		if index == program_counter {
			let string_aux = i[0].to_string();
			if string_aux.chars().last().unwrap() == ":".chars().next().unwrap() {
				return Err("label".to_string());
			}
			return Ok(i[0].to_string());
		} else {
			index = index + 1;
		}
	}
	Err("program_counter excedeu o limite do programa!".to_string())
}

//Decode instruction --> decodifica a instrução (define o que ela vai fazer)
fn decode_instruction(instruction: &String) -> u32 {
	let mut decoded_instruciton = 0;
	let decoded_instruction = match instruction.to_string() {
		//Instruções com apenas 2 operandos
		"addl".to_string()  => 0,
		"movl".to_string()  => 1,
		"subl".to_string()  => 2,
		"cmpl".to_string()  => 3,
		"imull".to_string() => 4,
		//Instruções com 1 operando
		"jmp".to_string()   => 5,
		"decl".to_string()  => 6,
		"call".to_string()  => 7,
		"jne".to_string()   => 8,
		"pushl".to_string() => 9,
		"incl".to_string()  => 10,
		"jl".to_string()    => 11,
		//Instruções com nenhum operando
		"leave".to_string() => 12,
		"ret".to_string()   => 13,
		_                   => panic!("Comando '" instruction "' não reconhecido!")
	};
	decoded_instruction
}

//Operand Calculus --> calcula o endereço do operando
fn operand_calculation(decoded_instruction: u32) -> u32 {
	let result_oc = 0;
	if decoded_instruction <= 12 {
		result_oc = 0;
	} else if decoded_instruction <= 5 {
		result_oc = 1;
	} else {
		result_oc = 2;
	}
	result_oc
}

fn operand_check(program: &Vec<Vec<String>>, operand_number: u32, program_counter: u32, all_operands: Vec<Operand>) -> String {
	let rng = thread_rng().gen_i32(10);
	let mut op_operands: String;
	let mut count = 0;
	//Verifica se o operando já está "cadastrado"
	for i in all_operands {
		if i.name == program[program_counter as usize][1] {
			let op_operands = format!("{} {}",1,i.position);
			return op_operands;
		}
		count = i.position;
	}
	//Passar 'reto' o for, significa que o operando ainda não foi registrado
	all_operands.push( 
			Operand {
				name: program[program_counter as usize][1],
				value: rng,
				position: count
		});
	return op_operands;
}

//Fetch Operand --> pega o conteúdo do operando
fn operand_fetch(program: &Vec<Vec<String>>, operand_number: u32, program_counter: u32, all_operands: Vec<Operand>) -> String {
	/*let operands = match operand_number {
		2 => program[program_counter as usize][1].to_string(),
		1 => program[program_counter as usize][1].to_string(),
		0 => "".to_string(),
		_ => panic!("Falha na busca por operandos!")
	};
	operands*/
	if operand_number == 1 {
		
	} else if operand_number == 2 {

	}
	return "".to_string();
}

fn jump(program: &Vec<Vec<String>>, jump_label: String) -> Result<Jmp, i32> {
	let mut index = 0;
	//Varre as linhas do programa
	for i in program {
		let mut aux = i[0].to_string();
		aux.pop();
		index = index + 1;
		//Quando a label para a qual se deve pular for igual a label do programa
		if jump_label == aux {
		//Retorna a diferença ( novo número da linha )
			return Ok(Jmp {
				is_jump: true,
				program_counter: index
			});
		}
	}
	Err(index)
}

//Execute Instruction --> realiza a instrução com o operando desejado
fn execute_instruction( program: &Vec<Vec<String>>, jump_label: String, op_code: u32, program_counter: u32, program_size: u32) -> Result<Jmp, i32> {
	if op_code == 1 { // Jump normal
		return jump(&program, jump_label);
	} else if op_code == 2 {//Jump condicional
		let rng = thread_rng().gen_bool(0.5);
		//Condição do pulo é válida -> pula linha
		if rng {
			return jump(&program, jump_label);
		}
	} else if op_code == 4 {
		return Ok(Jmp {
			is_jump: false,
			program_counter: -1
		});
	}
	if program_counter >= program_size {
		return Ok(Jmp {
			is_jump: false,
			program_counter: -1
		});
	} else {
		return Ok(Jmp {
			is_jump: false,
			program_counter: (program_counter + 1) as i32
		});
	}
}

//Write Operand --> grava o resultado
fn write_operand(program_counter: i32) {
	//Neste caso, o WO não faz nada
	if program_counter != -1 {
		print!("I{}\t", program_counter);
	} else {
		print!("\t");
	}
}

fn end_program(program_counter1: i32, program_counter2: i32, program_counter3: i32, program_counter4: i32, program_counter5: i32, program_counter6: i32) -> bool {
	if program_counter1 != -1 || program_counter2 != -1 || program_counter3 != -1 || program_counter4 != -1 || program_counter5 != -1 || program_counter6 != -1 {
		return false;
	}
	true
}

fn read_file(file_name: String) -> Vec<Vec<String>> {
	//Abertura do arquivo
	let content = fs::read_to_string(file_name)
		.expect("Falha na leitura do arquivo!");
	let content_lines = content.split("\n")
		.collect::<Vec<&str>>();
	let mut content_2d_vec: Vec<Vec<&str>> = Vec::new();
	for i in content_lines {
		let line = i.split_whitespace()
			.collect::<Vec<&str>>();
		content_2d_vec.push(line);
	}
	let mut content_string: Vec<Vec<String>> = Vec::new();
	let mut index = 0;
	for i in content_2d_vec {
		content_string.push(Vec::new());
		for j in i {
			content_string[index].push(j.to_string());
		}
		index = index + 1;
	}
	content_string
}

fn main() {
	//Leitura do nome do arquivo
	println!("Arquivo: ");
	let mut file_name = String::new();
	io::stdin().read_line( &mut file_name )
		.expect("Falha na leitura");
	file_name.pop();//tira a quebra de linha
	let program = read_file(file_name);
	let program_size = program.len();
	let mut program_counter = 0;
	let mut buffer: Vec<Instruction> = Vec::new();
	let mut all_operands: Vec<Operand> = Vec::new();
	let mut jump_flag = false;
	for _index in 0..6 {
		buffer.push(
			Instruction {
				program_counter: -1,
				buffer: "".to_string(),
				op_code: -1,
				operand: "".to_string()});
	}
	println!("FI\tDI\tCO\tFO\tEI\tWO");
	loop {
		buffer[0].program_counter = program_counter;
		if buffer[0].program_counter != -1{
			buffer[0].buffer = match instruction_fetch(&program, buffer[0].program_counter as u32) {
				Ok(value) => value,
				Err(value) => {
					if value == "label".to_string() {
						program_counter = program_counter + 1;
						continue;
					} else {
						panic!(value);
					}
				}
			};
		}
		if buffer[1].program_counter != -1 {
			buffer[1].op_code = decode_instruction(&buffer[1].buffer) as i32;
		}
		if buffer[2].program_counter != -1 {
			buffer[2].buffer = operand_calculation(buffer[2].op_code as u32).to_string();
		}
		if buffer[3].program_counter != -1 {
			match buffer[3].buffer.parse::<u32>() {
				Ok(num) => buffer[3].operand = operand_fetch(&program, num, buffer[3].program_counter as u32),
				Err(_) => panic!("Falha na leitura do buffer no espaco 3")
			}
		}
		if buffer[4].program_counter != -1 {
			program_counter = match execute_instruction(&program, buffer[4].operand.to_string(), buffer[4].op_code as u32, program_counter as u32, program_size as u32) {
				Ok(value) => {
					if value.is_jump {
						jump_flag = true;
					} else {
						jump_flag = false;
					}
					value.program_counter
				}
				Err(_) => panic!("Falha na execucao do programa")
			}
		} else {
			if program_counter != -1 {
				jump_flag = false;
				program_counter = program_counter + 1;
			}
		}
		if program_counter >= program_size as i32 {
			program_counter = -1;
		}
		for i in &buffer {
			write_operand(i.program_counter);
		}
		println!();
		for index in 0..5 {
			buffer[5 - index].program_counter = buffer[5 - index - 1].program_counter;
			buffer[5 - index].buffer = buffer[5 - index - 1].buffer.to_string();
			buffer[5 - index].op_code = buffer[5 - index - 1].op_code;
			buffer[5 - index].operand = buffer[5 - index - 1].operand.to_string();
		}
		if jump_flag {
			for index in 0..5 {
				buffer[index].program_counter = -1;
				buffer[index].buffer = "".to_string();
				buffer[index].op_code = -1;
				buffer[index].operand = "".to_string();
			}
		}
		buffer[0].program_counter = program_counter;
		if end_program(buffer[0].program_counter, buffer[1].program_counter, buffer[2].program_counter, buffer[3].program_counter, buffer[4].program_counter, buffer[5].program_counter) {
			break;
		}
		let mut _aux: String = String::new();
		io::stdin().read_line(&mut _aux)
			.expect("");
	}
}
