using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GraphManager: MonoBehaviour
{
    public static GraphManager Instance = null;

    // Node : (List of incoming edges, List of outgoing edges)
    public Dictionary<Node, (List<EdgeData>, List<EdgeData>)> m_graphContainer = new Dictionary<Node, (List<EdgeData>, List<EdgeData>)>();                         

    void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }

        else if (Instance != this)
        {
            Destroy(gameObject);
        }

        DontDestroyOnLoad(gameObject);
    }

    public void addEdgeLine(Node from, Node to, EdgeData edge_data)
    {
        if (!m_graphContainer.ContainsKey(from))
        {
            m_graphContainer.Add(from, (new List<EdgeData>(), new List<EdgeData>()));
        }

        if (!m_graphContainer.ContainsKey(to))
        {
            m_graphContainer.Add(to, (new List<EdgeData>(), new List<EdgeData>()));
        }

        m_graphContainer[from].Item2.Add(edge_data);
        m_graphContainer[to].Item1.Add(edge_data);
    }

    public void deleteNode(Node node){
        Debug.Log("Deleting node " + node.m_nodeName);
        if (m_graphContainer.ContainsKey(node))
        {
            foreach (EdgeData edge in m_graphContainer[node].Item1)
            {
                if (edge != null)
                {
                    Destroy(edge.gameObject);
                }
            }

            foreach (EdgeData edge in m_graphContainer[node].Item2)
            {
                if (edge != null)
                {
                    Destroy(edge.gameObject);
                }
            }

            foreach(Node n in m_graphContainer.Keys){
                if (n.m_connectedNodes.ContainsKey(node))
                {
                    n.m_connectedNodes.Remove(node);
                }
            }

            m_graphContainer.Remove(node);
        }
    }

    public (List<EdgeData>, List<EdgeData>) getEdgeList(Node node){
        if (m_graphContainer.ContainsKey(node))
        {
            Debug.Log("Found node");
            return m_graphContainer[node];
        }

        return (new List<EdgeData>(), new List<EdgeData>());
    }
}

