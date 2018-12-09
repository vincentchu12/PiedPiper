.class public bit_ops
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static a I

.method public <init>()V

	aload_0
	invokenonvirtual    java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

.method public static main([Ljava/lang/String;)V

	new RunTimer
	dup
	invokenonvirtual RunTimer/<init>()V
	putstatic        bit_ops/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        bit_ops/_standardIn LPascalTextIn;
	ldc	9
	putstatic	bit_ops/a I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"%d"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	bit_ops/a I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"%d%d%d%d"
	ldc	4
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	bit_ops/a I
	ldc	3
	ishr
	iconst_1
	iand
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	ldc	1
	getstatic	bit_ops/a I
	ldc	2
	ishr
	iconst_1
	iand
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	ldc	2
	getstatic	bit_ops/a I
	ldc	1
	ishr
	iconst_1
	iand
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	dup
	ldc	3
	getstatic	bit_ops/a I
	ldc	0
	ishr
	iconst_1
	iand
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc	0
	ldc 0
	if_icmpeq Label_1
	goto Label_0
Label_0:
	getstatic	bit_ops/a I
	iconst_1
	ldc	3
	ishl
	ior
	goto Label_2
Label_1:
	getstatic	bit_ops/a I
	iconst_1
	ldc	3
	ishl
	ineg
	iconst_1
	isub
	iand
Label_2:
	putstatic	bit_ops/a I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"%d"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	bit_ops/a I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc	1
	ldc 0
	if_icmpeq Label_4
	goto Label_3
Label_3:
	getstatic	bit_ops/a I
	iconst_1
	ldc	1
	ishl
	ior
	goto Label_5
Label_4:
	getstatic	bit_ops/a I
	iconst_1
	ldc	1
	ishl
	ineg
	iconst_1
	isub
	iand
Label_5:
	putstatic	bit_ops/a I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"%d"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	bit_ops/a I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V

	getstatic     bit_ops/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
