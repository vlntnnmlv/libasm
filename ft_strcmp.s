			global		_ft_strcmp
			section		.text
_ft_strcmp:
			xor rcx, rcx
			xor rax, rax
			xor rdx, rdx
		loop:
			cmp byte[rdi + rcx], 0x00
			je exit
			cmp byte[rsi + rcx], 0x00
			je exit
			mov al, byte[rdi + rcx]
			cmp al, byte[rsi + rcx]
			jne exit
			inc rcx
			jmp loop
exit:
			mov al, byte[rdi + rcx]
			mov dl, byte[rsi + rcx]
			sub rax, rdx
			ret