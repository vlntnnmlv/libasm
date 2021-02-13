			global		_ft_strlen
			section		.text

_ft_strlen:
			xor	rax, rax
			mov	r8, rdi
			cmp	byte[r8], 0x00
			je	exit
			loop:
				cmp byte[rdi+rax], 0x00
				je exit
				inc rax
				jmp loop
exit:
			ret
