function LinkedList() {

    let Node = function(element){
        this.element = element;
        this.next = null;
    };

    let length = 0;
    let head = null;

    this.append = function(element){

        let node = new Node(element);

        if(head === null){
            head = node;
        }else{
            let current = head;

            while(current.next){
                current = current.next;
            }

            current.next = node;
        }

        length++;
    };

    this.insert = function(position, element){};

    this.removeAt = function(position){
        if(position > -1 && position < length){
            if(position === 0){
                head = head.next;
            }else{
                let previous = null;
                let current = head;
                let index = 0;
                while(index < position){
                    [previous, current] = [current, current.next];
                    index++;
                }
                previous.next = current.next;
                length--;
                return current.element;
            }
        }else{
            return null;
        }

    };

    this.remove = function(element){};

    this.indexOf = function(element){};
    this.isEmpty = function(){};

    this.size = function(){
        return length;
    };

    this.toString = function(){};

    this.print = function(){
        let current = head;
        while(current){
            console.log(current.element);
            current = current.next;
        }
    };
}
let s = 'hello, world!';

module.exports = [LinkedList, s];
