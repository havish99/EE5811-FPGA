//Program for blinking LED
module example(input wire scl, output reg[0:0] mosi, output reg ss1, output reg ss2);

reg[20:0] delay;
reg[27:0] counter=28'd0;
parameter DIVISOR = 28'd50;
reg[0:15] xx = 16'b1100011100101001;
//reg[0:7] xx1 = 8'b10101010;
reg[4:0] A ;
reg[3:0] B;
reg[1:0] flag;



initial begin
A = 0;
ss1 = 1;
ss2 = 1; 
delay=0;
flag = 0;
B = 0;
end

//assign scl = (counter<DIVISOR/2)?1'b0:1'b1;
//if(delay==21'b111101000010010000000) delay=22'b0;
//if(delay==21'b0) begin
always@(posedge scl) begin
	if(A<=7) begin 
		if(ss1!=0)ss1 = 0;
		if(ss2!=1)ss2 = 1;
		mosi = xx[A];
		A = A + 1;
	end
	else if(A>=8 && A<=15) begin
		if(ss1!=1) ss1 = 1;
		if(ss2!=0) ss2 = 0;
		mosi = xx[A];
		A = A + 1;
	end
	else begin
		if(A==16) begin 
		ss1 = 1;
		ss2 = 1;
		//flag = 1;
		end
		//if(B==8) ss2 = 1;
		if(delay == 21'b011110100001001000000) begin 
			//if(ss1==1) begin
			A = 0;
			//flag = 0;
			//end
			//else if(B==8 && ss2==1)
			//A = 0;
			delay = 0;
			//flag = 1;
		end
		delay = delay + 1;
	end
	
	
end

endmodule
