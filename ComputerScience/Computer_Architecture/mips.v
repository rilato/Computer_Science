`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2023/05/06 18:17:17
// Design Name: 
// Module Name: mips
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

module pcreg(
    input  wire clk,
    input  wire reset,
    output reg  [31:0] pc,
    input  wire [31:0] pcnext
    );
    
    always @(posedge clk, posedge reset) begin
        if (reset) pc <= 32'h00000000;
        else       pc <= pcnext;
    end
    
endmodule

module myadder (
    input  wire [31:0] a,
    input  wire [31:0] b,
    output wire [31:0] y
    );
    
    assign y = a + b;
    
endmodule

module mips(
    input  wire clk,
    input  wire reset,
    output wire [31:0] pc
    );
    
    wire [31:0] pcnext;
    
    pcreg mips_pc (.clk    (clk),
                   .reset  (reset),
                   .pc     (pc),
                   .pcnext (pcnext));
                   
    myadder pcadd4 (.a (pc),
                    .b (32'b100),
                    .y (pcnext));
                    
endmodule
