.class public input
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static a I
.field private static b I
.field private static c I
.field private static i I
.field private static foo Z

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
	putstatic        input/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        input/_standardIn LPascalTextIn;
	ldc	3
	putstatic	input/b I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of b is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/b I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	ldc	4
	putstatic	input/a I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of a is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/a I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	ldc	0
	putstatic	input/foo Z
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of foo is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/foo Z
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	getstatic	input/foo Z
	ldc	1
	if_icmpeq Label_0
	ldc	4
	putstatic	input/c I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of c is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/c I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	goto Label_1
Label_0:
	ldc	9
	putstatic	input/c I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of c is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/c I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	goto Label_1
Label_1:
	getstatic	input/a I
	getstatic	input/b I
	if_icmplt Label_2
	getstatic	input/a I
	getstatic	input/b I
	if_icmpgt Label_3
	ldc	5
	ldc	3
	imul
	putstatic	input/c I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of c is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/c I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	goto Label_4
Label_2:
	ldc	3
	ldc	1
	iadd
	putstatic	input/c I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of c is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/c I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	goto Label_4
Label_3:
	ldc	3
	ldc	9
	irem
	putstatic	input/c I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of c is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/c I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	goto Label_4
Label_4:
	ldc	0
	putstatic	input/i I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of i is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/i I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
Label_5:
	getstatic	input/i I
	getstatic	input/c I
	if_icmplt Label_6
	goto Label_7
Label_6:
	getstatic	input/a I
	ldc	3
	iadd
	putstatic	input/a I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of a is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/a I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	getstatic	input/i I
	ldc	1
	iadd
	putstatic	input/i I
	; Assignment
		getstatic	java/lang/System/out Ljava/io/PrintStream;
		ldc	"The value of i is %d\n"
		iconst_1	
		anewarray	java/lang/Object
		dup
		iconst_0
		getstatic	input/i I
		invokestatic	java/lang/Integer.valueOf(I)Ljava/lang/Integer;
		aastore
		invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
		invokevirtual java/io/PrintStream.print(Ljava/lang/String;)V
	goto Label_5
Label_7:

	getstatic     input/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
