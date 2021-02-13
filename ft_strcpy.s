			global		_ft_strcpy
			section		.text
_ft_strcpy:
				xor rcx, rcx
				xor rax, rax
			loop:
					cmp byte[rsi + rcx], 0x00
					je exit
					mov al, byte[rsi + rcx]
					mov byte[rdi + rcx], al
					inc rcx
					jmp loop
exit:
				mov al, byte[rsi + rcx]
				mov byte[rdi + rcx], al
				mov rax, rdi
				ret