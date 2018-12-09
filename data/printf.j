.class public printf
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
	putstatic        printf/_runTimer LRunTimer;
	new PascalTextIn
	dup
	invokenonvirtual PascalTextIn/<init>()V
	putstatic        printf/_standardIn LPascalTextIn;
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"This is just a regular string print"
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"This is a print with an integer: %d"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	ldc	4
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"This is a print with an string: %s"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	ldc	"Hello!"
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
	ldc	19
	putstatic	printf/a I
	getstatic java/lang/System/out Ljava/io/PrintStream;
	ldc	"This is a print with a variable: %d"
	ldc	1
	anewarray java/lang/Object
	dup
	ldc	0
	getstatic	printf/a I
	invokestatic java/lang/Integer.valueOf(I)Ljava/lang/Integer;
	aastore
	invokestatic  java/lang/String.format(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/String;
	invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V

	getstatic     printf/_runTimer LRunTimer;
	invokevirtual RunTimer.printElapsedTime()V

	return

.limit locals 16
.limit stack 16
.end method
