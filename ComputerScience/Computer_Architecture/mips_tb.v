`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/06 18:17:44
// Design Name: 
// Module Name: mips_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module mips_tb(

    );
    
    reg         clk, reset;
    wire [31:0] pc;
    
    mips u1 (clk, reset, pc);
    
    // initialize clk and reset
    initial begin
        #0  clk   = 1'b0;
            reset = 1'b0;
        #10 reset = 1'b1;
        #20 reset = 1'b0;
        #50 $finish;
    end
       
    always #5
    begin
        clk = ~clk;
    end
    
    initial
        $monitor("time = ", $time, " pc = %x", pc);
        
endmodule
