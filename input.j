<<<<<<< HEAD
=======
.class public input
.super java/lang/Object

.field private static _runTimer LRunTimer;
.field private static _standardIn LPascalTextIn;
<<<<<<< HEAD
>>>>>>> 6363286... add functions
=======
.field private static b I
.field private static main_a I
.field private static foo_a I
.field private static foo_b I
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
	putstatic        input/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        input/_standardIn LPascalTextIn;
	ldc	4
	putstatic	input/b I
	getstatic	input/foo_a I
	putstatic	input/b I
	ldc	3
	putstatic	input/a I

	getstatic     input/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
>>>>>>> aab952d... Pass1 function declarations
