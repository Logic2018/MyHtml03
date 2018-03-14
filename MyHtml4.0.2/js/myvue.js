
































//	var app =new Vue({
//		el:"#app",
//		data:{
//			userdata:"",
//			username:"",
//			
//		},
//		methods:{
//			fun1:function(){
//
//				var url="../json/list.json";
//				self=this;
//				$.get(url,function(userdata){
//					
//					alert(self.username);
//					console.log(userdata.data[0].username);
//					
//				},"json");
//			},
//		},
//	});

//	var app =new Vue({		
//		el:"#app",
//		data:{
//			userdata:"",
//			username:"",
//			message:"",
//			
//		},
//		methods:{
//			fun1:function(){
//
//				var url="../json/list.json";
//				self=this;
//				$.get(url,function(userdata){
//				var k=0;
//					for(var i=0;i<userdata.data.length;i++){
//						console.log(self.username);
//						console.log(userdata.data[i].username);					
//						if(self.username==userdata.data[i].username){								
//							k++;
//						}						
//					}
//					if(k>0){
//						self.message="error";
//					}else{
//						self.message="ok";
//					}
//					
//				},"json");
//			},
//		},
//	});


//var app5 = new Vue({
//el: '#app-5',
//data: {
//  message: 'Hello Vue.js!'
//},
//methods: {
//  reverseMessage: function () {
//    this.message = this.message.split('').reverse().join('')
//  }
//}
//})
//

//	var app = new Vue({
//		el:"#app",
//		data:{
//			todos:[
//				 { text: '学习 JavaScript' },
//			     { text: '学习 Vue' },
//			     { text: '整个牛项目' },
//				]
//		}
//		
//	})
//	
	
//	var app = new Vue({
//		el:"#app",
//		data:{
//			message: new Date().toLocaleString(),
//		}
//		
//	})