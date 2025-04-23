let students = [];

function addStudent() {
  const rollNo = document.getElementById("rollNo").value.trim();
  const name = document.getElementById("name").value.trim();
  const marks = document.getElementById("marks").value.trim();

  if (!rollNo || !name || !marks) {
    alert("Please fill all fields");
    return;
  }

  // Check for duplicate roll number
  if (students.some((student) => student.rollNo == rollNo)) {
    alert("Roll number already exists!");
    return;
  }

  students.push({ rollNo, name, marks });
  displayStudents();
  clearInputs();
}

function displayStudents() {
  const list = document.getElementById("studentsList");
  list.innerHTML = "";

  students.forEach((student, index) => {
    const div = document.createElement("div");
    div.className = "student-card";
    div.innerHTML = `
          <strong>Roll No:</strong> ${student.rollNo}<br>
          <strong>Name:</strong> ${student.name}<br>
          <strong>Marks:</strong> ${student.marks}
          <button onclick="deleteStudent(${index})">Delete</button>
        `;
    list.appendChild(div);
  });
}

function deleteStudent(index) {
  if (confirm("Are you sure you want to delete this record?")) {
    students.splice(index, 1);
    displayStudents();
  }
}

function searchStudent() {
  const roll = document.getElementById("searchRoll").value;
  const student = students.find((s) => s.rollNo == roll);

  if (student) {
    alert(`Found!\nName: ${student.name}\nMarks: ${student.marks}`);
  } else {
    alert("Student not found.");
  }
}

function clearInputs() {
  document.getElementById("rollNo").value = "";
  document.getElementById("name").value = "";
  document.getElementById("marks").value = "";
}
