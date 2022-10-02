// JavaScript source code
const navMenu = document.getElementById('nav-menu'),
     toggleMenu = document.getElementById('toggle-menu'),
     closeMenu = document.getElementById('close-menu')
 
toggleMenu.addEventListener('click',() => {
 navMenu.classList.toggle('show')
})
closeMenu.addEventListener('click',() => {
 navMenu.classList.remove('show')
})
 
 
 
function calculateLotData() {
   //lOT CAP
 
   Lotcap = [500, 500, 500, 500, 250, 250, 250, 125, 125, 125, 125, 125, 125, 125, 50, 1200, 1000, 800, 800, 800];
   //LOT %
   LP = [0.3, 0.59, 0.696, 0.472, 0.468, 0.572, 0.524, 0.352, 0.392, 0.168, 0.288, 0.4, 0.128, 0.208, 0.584, 0.462, 0.118, 0.721, 0.486, 0.69];
   //LOT CARS
   //[('lot 25', 150.0), ('lot 26', 295.0), ('lot 50N', 348.0), ('lot 50S', 236.0), ('lot 27', 117.0), ('lot 30', 143.0), ('lot 51', 131.0), ('lot 34', 44.0), ('lot 36', 49.0), ('lot 38', 21.0), ('lot 45', 36.0), ('lot 46', 50.0), ('lot 52', 16.0), ('lot 53', 26.0), ('lot 35', 29.2), ('WestGarage', 142.0), ('lot 49', 462.0), ('NorthGarage', 577.0), ('CentralGarage', 389.0), ('SouthGarage', 552.0)]
   //LOT CARS SORTED
   LCS = [16.0, 21.0, 26.0, 29.0, 36.0, 44.0, 49.0, 50.0, 117.0, 131.0, 142.0, 143.0, 150.0, 236.0, 295.0, 348.0, 389.0, 462.0, 552.0, 577.0];
   lotNames = ['25', '26', '50N', '50S', '27', '30', '51', '34', '36', '38', '45', '46', '52', '53', '35', 'West Campus Garage', '49', 'College Park N. Garage', 'College Park C. Garage', 'College Park S. Garage']
   let lotData = [];
   if (Lotcap.length === LP.length && Lotcap.length === LCS.length) {
       //console.log("array lenghts DO match")
       for (let idx = 0; idx < Lotcap.length; idx++) {
           //console.log(`lot: ${lot}`)
           let lotObj = {
               lotNumber: lotNames[idx],
               lotCap: 0,
               lotPercentage: 0,
               lotCarsSorted: 0
           };
           lotObj.lotCap = Lotcap[idx]
           //console.log(lotNumber)
           lotObj.lotPercentage = LP[idx]
           lotObj.lotCarsSorted = LCS[idx]
           lotData.push(lotObj)
       }
   } else {
       console.error("array lengths dont match")
   }
 
   return lotData
}
 
function displayLots() {
   const lotContainer = document.querySelector('.container')
   const lots = calculateLotData();
   for (const lot of lots) {
       let lotElement = document.createElement('div')
       lotElement.innerHTML = `Lot ${lot.lotNumber} => lotCap: ${lot.lotCap}, lotPercentage: ${lot.lotPercentage}, lotCarsSorted: ${lot.lotCarsSorted}`
       LP1(lotElement, lot)
       lotContainer.appendChild(lotElement)
   }
}

function LP1(lotElement, lotData) {
       const lp = lotData.lotPercentage
       console.log(`thevalue = ${lp} | <= .2 : ${lp <= .2} <= .4 : ${lp <= .4} <= .6 : ${lp <= .6} <= .8 : ${lp <= .8} <= 1 : ${ lp <= 1}`)
       if (lp <= .2) {
           lotElement.style.setProperty('color', '#ABFF4F'); // neon green
       } else if (lp <= .4) {
           lotElement.style.setProperty('color', '#29BF12'); // green
       } else if (lp <= .6) {
           lotElement.style.setProperty('color', '#08BDBD'); // teal
       } else if (lp <= .8) {
           lotElement.style.setProperty('color', '#FF9914'); // orange
       } else if (lp <= 1) {
           lotElement.style.setProperty('color', "#F21b3F"); // red
       } else {
           lotElement.style.setProperty('color', 'black');
       }
}
 
window.addEventListener('load', (e) => {
   colorchange()
   displayLots()
})
 
var color = "red"
function colorchange() {
   let element = document.getElementById("lot1")
   console.log(element);
   element.style.backgroundColor = color;
}
 

/*if (l2[1] <= .2) {
   color = "green";
   console.log(color);
} else if (l2[1] <= .4) {
   color = ("blue");
   console.log(color);
} else if (l2[1] <= .6) {
   color = ("yellow");
   console.log(color);
} else if (l2[1] <= .8) {
   color = ("orange");
   console.log(color);
} else if (l2[1] <= 1) {
   color = ("red");
   console.log(color);
}
if (l2[2] <= .2) {
   color = "green";
   console.log(color);
} else if (l2[0] <= .4) {
   color = ("blue");
   console.log(color);
} else if (l2[0] <= .6) {
   color = ("yellow");
   console.log(color);
} else if (l2[0] <= .8) {
   color = ("orange");
   console.log(color);
} else if (l2[0] <= 1) {
   color = ("red");
   console.log(color);
}
*/
