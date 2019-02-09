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
use std::env;
use std::fs::File;
use std::io::prelude::*;

//Fetch instruction --> pega a próxima instrução
fn FI( String instruction ) {
	let instructionId = DI( instruction );
	//Caso o valor lido corresponda a uma label
	if  instructionId == -1 {
		let mut index   = index + 1; 
		labels[ index ] = instruction;
		let mut instruction   = contents.next();
		let mut instructionId = DI( instruction );
	} else {
		print!(" FI -->");
	}
}

//Decode instruction --> decodifica a instrução (define o que ela vai fazer)
fn DI() {
	//Definir todos os comandos do assembly em um arquivo separado
	let commandList : [String, 11] = ["pushl", "movl", "subl","cmpl","jne","jmp","decl","call","imull","leave","ret"];
	print!(" DI -->");
}

//Operand Calculus --> calcula o endereço do operando
fn CO() {
	print(" CO -->");
}

//Fetch Operand --> pega o conteúdo do operando
fn FO() {
	print!(" FO -->");
}

//Execute Instruction --> realiza a instrução com o operando desejado
fn EI() {
	print!(" EI --");
}

//Write Operand --> grava o resultado
fn WO() {
	print!(" WO ");
}

fn Main() {
	let labels;
	let index = -1;
	//Leitura do nome do arquivo
	println!("Arquivo: ");
	let fileName = String::new();
	io::stdin().read_line( &mut fileName )?;

	//Abertura do arquivo
	let file = File::open( fileName ).expect( "Arquivo não encontrado!" );
	let contents = String::new();
	file.read_to_string( &mut contents ).expect( "Erro na leitura do arquivo" );

	//.split_whitespace() divide a string em várias, separando-as pelos espaços em branco
	let mut contents = contents.split_whitespace();
	let instruction = contents.next();

	//Enquanto o próximo pedaço da String for diferente de nulo
	while { assert_ne!( None, instruction ) } {
		print!("\nInstrução ")
		FI( instruction );

		//Leitura da próxima instrução
		let mut instruction = contents.next();
	}
}
