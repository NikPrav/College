const cvs = document.getElementById("bg");
const ctx = cvs.getContext("2d");
let vtotal=0,htotal=0,movedir="down";


//Size of a unit
const box = 32;

var odir = {
    up:0,
    left:0,
    right:16*box,
    down:14*box
}
//Load Images
const ground = new Image();
ground.src= "img/ground.png";

//Define and initialise the position of the bot
var bot = { 
    x : 1 * box,
    y : 3 * box
};

//Define the positions of obstacles
let obs = [];
for(let i=0; i<10; ++i)
{
    obs[i]= {
        x : Math.floor(Math.random()*16+2) * box,
        y : Math.floor(Math.random()*14+4) * box
    }
}
let d="STOP";
var newpos = {
    x:0,y:0
};
newpos.x=bot.x;
    newpos.y=bot.y;
var dist = {
    left:0,right:0,up:0,down:0
};

//Control Proxy

document.addEventListener("keydown",direction)

//document.addEventListener("keyup",st)

function st(event) {
    d="STOP";
    
}

function direction(event){
    if(event.keyCode == 37){
        d="LEFT";
    }
    else if(event.keyCode == 38){
        d="UP";
    }
    else if(event.keyCode == 39){
        d="RIGHT";
    }
    else if(event.keyCode == 40){
        d="DOWN";
    }
    else if(event.keyCode == 32){
        d="STOP"; 
    }
}

//Moving the bot according to the chosen direction
function newdir()
{
    newpos.x=bot.x;
    newpos.y=bot.y;
    if(d == "DOWN")
        newpos.y+=box;
    if(d == "UP")
        newpos.y-=box;
    if(d == "LEFT")
        newpos.x-=box;
    if(d == "RIGHT")
        newpos.x+=box;

}

//Returns the dist from the nearest obstacle on all sides
function sensor() {
    var right=16*box-newpos.x+1*box,down=14*box-newpos.y+3*box,left=16*box-right,up=14*box-down;
    for(var k=0; k<10; ++k)
    {
        
        if(obs[k].y==newpos.y)
        {
            var small=obs[k].x-newpos.x;
            //small-=box;
            if(small-box<right && small>=0)
            right=small-box;
            else if(small+box>(-left) && small<0)
            left=(-small)-box;
        }
        else if(obs[k].x==newpos.x)
        {
            var small=obs[k].y-newpos.y;
            //small-=box;
            if(small-box<down && small>=0)
            down=small-box;
            else if(small+box>(-up) && small<0)
            up=(-small)-box;

        }
        dist.right=right;
        dist.left=left;
        dist.up=up;
        dist.down=down;
    }

    
}

var dap=0;
var r=0;
var ken=0;

//Function to move the bot
function movebot()
{
    if(movedir=="down") //While the bot is moving down
    {
        vtotal+=odir.down-dist.down;
        //dap=0;
        document.getElementById("vt").innerHTML="vtotal="+vtotal/box;
        document.getElementById("dd").innerHTML="Ddown="+dist.down/box + " Odown="+odir.down/box;
        //document.getElementById("od").innerHTML="Odown="+odir.down/box;
        odir.up=dist.up;
        odir.down=dist.down;
        odir.left=dist.left;
        odir.right=dist.right;
        console.log("dist="+ dist.down)
        console.log("vtotal="+vtotal)
        if(vtotal<14*box){
            d="DOWN";
            if(dist.down==0)
            {
                d="RIGHT";
                dap=1;
                ++r;
                ken=1
                return 0;
            }
            else if(dist.left!=0 && ken==0 && r!=0)
            {
                d="LEFT";
                --r;
                dap=1;
                return 0;
            }
            dap=0;
            ken=0;
            

        }
        else{
            d="RIGHT";
            movedir="up";
            dap=1;
            vtotal=0 ;
            //return 0;
        }
        
    }
    else if(movedir=="up")//While the bot is moving up
    {   
        vtotal+=odir.up-dist.up;
        document.getElementById("vt").innerHTML="vtotal="+vtotal/box;
        document.getElementById("du").innerHTML="Dup="+dist.up/box + " Ou="+odir.up/box;
        //document.getElementById("ou").innerHTML="Ou="+odir.up/box;
        //dap=0;
        
        odir.up=dist.up;
        odir.down=dist.down;
        odir.left=dist.left;
        odir.right=dist.right;
        
        if(vtotal<14*box){

            d="UP";
            if(dist.up==0)
            {
                d="RIGHT";
                dap=1;
                ++r;
                ken=1;
                return 0;
            }
            else if(dist.left!=0 && dap==0 && r!=0)
            {
                d="LEFT";
                --r;
                dap=1;
                return 0;
            }
            dap=0;
            ken=0;
        }
        else{
            d="RIGHT";
            movedir="down";
            dap=1;
            vtotal=0;
            return 0;
        }
    }

    
}



//Draw everything to the canvas
var flag=false;
function draw()
{
    if(!flag){
    
    //Calculating the USS reading    
    sensor(); 
        
    //Moving the bot
    movebot();
        
    

    
     
    
    document.getElementById("rt").innerHTML="right="+dist.right/box + " left="+dist.left/box; 
    //document.getElementById("lt").innerHTML="left="+dist.left/box; 
    document.getElementById("up").innerHTML="up="+dist.up/box + " down="+dist.down/box; 
    document.getElementById("dn").innerHTML="bot.x="+bot.x/box + " bot.y="+bot.y/box; 
    for(let i=0;i<obs.length; ++i)
    {
        if(newpos.x==obs[i].x && newpos.y==obs[i].y)
            flag=true;
        else if(newpos.x>=18*box || newpos.y>=18*box)
            flag=true;
        else if(newpos.x<1*box || newpos.y<3*box)
            flag=true
        //changedir();
    }
    bot.x=newpos.x;
    bot.y=newpos.y;
    
    ctx.drawImage(ground,0,0);
    ctx.fillStyle = "blue";
    ctx.fillRect(bot.x,bot.y,box,box);
    ctx.strokeStyle = "red";
    ctx.strokeRect(bot.x,bot.y,box,box);
    
    for(let j=0; j<obs.length; ++j)
    {
        if(!(obs[j].x == 0 && obs[j] == 0))
        {
            ctx.fillStyle = "black";
            ctx.fillRect(obs[j].x,obs[j].y,box,box);
        }
            //ctx.strokeStyle = "yellow";
        //ctx.strokeRect(obs[j].x,obs[j].y,box,box);
    }
    //Finding next position of the bot 
    newdir();
    if(dap)
    {

        sensor();
        odir.up=dist.up;
        odir.down=dist.down;
        odir.left=dist.left;
        odir.right=dist.right;
        //vtotal=box;   
    }
}
//else
//alert("Error,Bitch!!")
    
}

let game = setInterval(draw,100);
//document.addEventListener("keydown",draw);
