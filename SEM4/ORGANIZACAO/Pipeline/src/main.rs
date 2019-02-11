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
use rand::*;
use std::io;
use std::fs;

//Fetch instruction --> pega a próxima instrução
fn FI( program: &Vec<&str>, program_counter: u32 ) -> String {
	let mut index = 1;
	let instruction: String = String::from("ZZZ");
	for i in program {
		if index == program_counter {
			let instruction = i;
			break;
		} else {
			index = index + 1;
		}
	}
	print!( "I{}  ", program_counter );
	instruction
}

//Decode instruction --> decodifica a instrução (define o que ela vai fazer)
fn DI( program: Vec<String>, program_counter: u32 ) {
	print!( "I{}  ", program_counter );
}

//Operand Calculus --> calcula o endereço do operando
fn CO( program: Vec<String>, program_counter: u32 ) {
	print!( "I{}  ", program_counter );
}

//Fetch Operand --> pega o conteúdo do operando
fn FO( program: Vec<String>, program_counter: u32 ) {
	print!( "I{}  ", program_counter );
}

//Execute Instruction --> realiza a instrução com o operando desejado
fn EI( program: Vec<String>, jump_label: String, op_code: u32, program_counter: u32 ) -> i32 {
	if op_code == 1 { // Jump normal(A ser redefinido o número)
		let index : i32 = -1;
		for i in program {
			let index = index + 1;
			if jump_label == i {
				return index
			}
		}
	} else if op_code == 2 {//Jump condicional
		let rng = rand::thread_rng();
		print!("{:?}",rng);
		return 0
	}
	print!( "I{}  ", program_counter );
	return 0
}

//Write Operand --> grava o resultado
fn WO( program: Vec<String>, program_counter: u32 ) {
	//Neste caso, o WO não faz nada
	print!( "I{}  ", program_counter );
}

fn ReadFile<'a>(file_name: String) -> Vec<&'a str> {
	//Abertura do arquivo
	let content = fs::read_to_string(file_name)
		.expect("Falha na leitura do arquivo!");
	let content = content.split_whitespace()
		.collect::<Vec<&str>>();
	content
}

fn main() {
	//Leitura do nome do arquivo
	println!("Arquivo: ");
	let mut file_name = String::new();
	io::stdin().read_line( &mut file_name )
		.expect("Falha na leitura");
	file_name.pop();//tira a quebra de linha
	let program = ReadFile(file_name);

	loop {
		let program_counter : u32 = 0;
		println!("     FI   DI   CO   FO   EI   WO");
		print!(  "{} -", program_counter );
		FI( &program, program_counter);
		/*if None == program[program_counter] {
			break;
		}*/
	}
}
