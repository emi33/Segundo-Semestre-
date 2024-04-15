import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class Main extends JFrame {
    private JTextArea textAreaLeft;
    private JTextArea textAreaRight;
    private JButton sendButton;
    private JButton addFieldButton;
    private JTextField xField;
    private JTextField yField;
    private ArrayList<String> textArray;
    private int fieldCounter;
    private JPanel fieldContainer;

    public Main() {
        setTitle("Panel con bloc de notas, botón y cuadro de texto");
        setSize(700, 300);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new GridLayout(1, 3)); // Diseño de cuadrícula con 1 fila y 3 columnas

        // Inicializar la lista para guardar el texto
        textArray = new ArrayList<>();
        fieldCounter = 0;

        // Crear el área de texto izquierda (similar a un bloc de notas)
        textAreaLeft = new JTextArea();
        JScrollPane scrollPaneLeft = new JScrollPane(textAreaLeft);

        // Crear panel para el botón de envío
        JPanel leftPanel = new JPanel();
        leftPanel.setLayout(new BorderLayout());
        sendButton = new JButton("Enviar");

        // Agregar acción al botón
        sendButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                // Obtener el texto del área de texto izquierda
                String text = textAreaLeft.getText();
                // Guardar el texto en el array
                textArray.add(text);
                // Limpiar el área de texto izquierda
                textAreaLeft.setText("");
                // Mostrar el contenido del array en el área de texto derecha
                updateRightTextArea();
            }
        });

        // Añadir el cuadro de texto y el botón al panel izquierdo
        leftPanel.add(scrollPaneLeft, BorderLayout.CENTER);
        leftPanel.add(sendButton, BorderLayout.SOUTH);

        // Crear el área de texto derecha para mostrar los datos
        textAreaRight = new JTextArea();
        textAreaRight.setEditable(false);
        JScrollPane scrollPaneRight = new JScrollPane(textAreaRight);

        // Crear panel derecho para mostrar el texto guardado
        JPanel rightPanel = new JPanel(new BorderLayout());
        rightPanel.add(scrollPaneRight, BorderLayout.CENTER);

        // Crear el tercer panel con los campos de números y botón para agregar cuadros de números dinámicos
        JPanel thirdPanel = new JPanel();
        thirdPanel.setLayout(new BorderLayout());

        // Crear un panel superior para los cuadros de números
        JPanel inputPanel = new JPanel(new FlowLayout());
        xField = new JTextField(5);
        yField = new JTextField(5);

        inputPanel.add(new JLabel("X:"));
        inputPanel.add(xField);
        inputPanel.add(new JLabel("Y:"));
        inputPanel.add(yField);

        // Crear un panel contenedor para los cuadros de números dinámicos
        fieldContainer = new JPanel();
        fieldContainer.setLayout(new GridLayout(0, 1));

        // Crear botón para agregar cuadros de números
        addFieldButton = new JButton("Add Field");
        addFieldButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addField();
            }
        });

        // Agregar los cuadros de números y el botón al panel
        thirdPanel.add(inputPanel, BorderLayout.NORTH);
        thirdPanel.add(new JScrollPane(fieldContainer), BorderLayout.CENTER);
        thirdPanel.add(addFieldButton, BorderLayout.SOUTH); // El botón está en la parte inferior

        // Agregar los paneles a la ventana
        add(leftPanel);
        add(rightPanel);
        add(thirdPanel);

        setVisible(true);
    }

    // Actualizar el área de texto derecha con los datos del array
    private void updateRightTextArea() {
        textAreaRight.setText(""); // Limpiar el área de texto derecha
        for (String text : textArray) {
            textAreaRight.append(text + "\n"); // Añadir cada texto al área de texto derecha
        }
    }

    // Agregar un nuevo cuadro de números a fieldContainer
    private void addField() {
        // Incrementar el contador
        fieldCounter++;

        // Crear un nuevo cuadro de números
        JTextField newField = new JTextField();

        // Crear un JLabel para mostrar el nombre de la variable t(n)
        JLabel tLabel = new JLabel("t(" + fieldCounter + "):");

        // Crear un panel para contener el JLabel y el JTextField
        JPanel fieldPanel = new JPanel();
        fieldPanel.setLayout(new FlowLayout());

        // Agregar el JLabel y el JTextField al panel
        fieldPanel.add(tLabel);
        fieldPanel.add(newField);

        // Agregar el panel a fieldContainer
        fieldContainer.add(fieldPanel);

        // Actualizar la ventana para reflejar los cambios
        fieldContainer.revalidate();
        fieldContainer.repaint();
    }

    public static void main(String[] args) {
        new Main();
    }
}