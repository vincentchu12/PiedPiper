.class public functions
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
.field private static powerOf_num I
.field private static powerOf_n I
.field private static powerOf_ans I
.field private static powerOf_i I

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
	putstatic        functions/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        functions/_standardIn LPascalTextIn;
	goto powerOf_end
powerOf:
	astore_1
	ldc	1
	putstatic	functions/powerOf_ans I
	ldc	0
	putstatic	functions/powerOf_i I
Label_0:
	getstatic	functions/powerOf_i I
	getstatic	functions/powerOf_n I
	if_icmplt Label_1
	goto Label_2
Label_1:
	getstatic	functions/powerOf_ans I
	getstatic	functions/powerOf_num I
	imul
	putstatic	functions/powerOf_ans I
	getstatic	functions/powerOf_i I
	iconst_1
	iadd
	putstatic	functions/powerOf_i I
	goto Label_0
Label_2:
	getstatic	functions/powerOf_ans I
	ret 1
powerOf_end:
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"4 to the power of 8 is: %d"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	ldc	4
	putstatic	functions/powerOf_num I
	ldc	8
	putstatic	functions/powerOf_n I
	jsr powerOf
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V

	getstatic     functions/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
