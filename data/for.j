.class public for
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static i I

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
	putstatic        for/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        for/_standardIn LPascalTextIn;
	ldc	0
	putstatic	for/i I
Label_0:
	getstatic	for/i I
	ldc	4
	if_icmplt Label_1
	goto Label_2
Label_1:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"Count %d!"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	for/i I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic	for/i I
	iconst_1
	iadd
	putstatic	for/i I
	goto Label_0
Label_2:

	getstatic     for/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
